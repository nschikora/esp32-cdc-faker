#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "driver/spi_master.h"
#include "soc/gpio_struct.h"
#include "esp_timer.h"
#include <unistd.h>
#include "esp_timer.h"
#include "esp_log.h"
#include "esp_sleep.h"
#include "sdkconfig.h"

#include "SPIHandler.h"


#define PIN_NUM_MISO 25
#define PIN_NUM_MOSI 23
#define PIN_NUM_CLK  19
#define PIN_NUM_CS   22

#define PIN_NUM_DC   21
#define PIN_NUM_RST  18
#define PIN_NUM_BCKL 5


#define SPI_TX_DELAY 874


SPIHandler& SPIHandler::instance() {
    static SPIHandler instance;
    return instance;
}

SPIHandler::SPIHandler() 
: _spi(nullptr)
, _command_tx_timer(nullptr)
, _data(nullptr)
, _length(0)
, _curByteIx(0)
, _sending(false)
{

}

SPIHandler::~SPIHandler() {

}

void SPIHandler::startup() {
    esp_err_t ret;

    spi_bus_config_t buscfg;
    buscfg.miso_io_num = PIN_NUM_MISO;
    buscfg.mosi_io_num = PIN_NUM_MOSI;
    buscfg.sclk_io_num = PIN_NUM_CLK;
    buscfg.quadwp_io_num = -1;
    buscfg.quadhd_io_num = -1;
    buscfg.max_transfer_sz = 1024;

    spi_device_interface_config_t devcfg;
    devcfg.clock_speed_hz = 62500;  //Clock out at 62500Hz
    devcfg.mode = 0;                //SPI mode 0
    devcfg.spics_io_num = -1;       //CS pin
    devcfg.queue_size = 7;          //We want to be able to queue 7 transactions at a time

    //Initialize the SPI bus
    ret=spi_bus_initialize(HSPI_HOST, &buscfg, 1);
    ESP_ERROR_CHECK(ret);

    //Attach the device to the SPI bus
    ret=spi_bus_add_device(HSPI_HOST, &devcfg, &_spi);
    ESP_ERROR_CHECK(ret);
}

void SPIHandler::send_cmd(const char *data, const uint8_t len)
{
    _sending = true;
    _data = data;
    _length = len;
    _curByteIx = 0;

    esp_timer_create_args_t tx_timer_args;
    tx_timer_args.callback = &SPIHandler::tx_timer_callback;
    tx_timer_args.name = "cmd_tx_timer";

    ESP_ERROR_CHECK(esp_timer_create(&tx_timer_args, &_command_tx_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(_command_tx_timer, SPI_TX_DELAY));
}

void SPIHandler::send_data(const char *data, int size)
{
    esp_err_t ret;
    spi_transaction_t t;
    memset(&t, 0, sizeof(t));           //Zero out the transaction
    t.length=size*8;                    //Len is in bytes, transaction length is in bits.
    t.tx_buffer=data;                   //Data
    ret=spi_device_transmit(_spi, &t);  //Transmit!
    assert(ret==ESP_OK);                //Should have had no issues.
}

bool SPIHandler::delete_timer_if_done() {
    if (_curByteIx >= _length) {
        ESP_ERROR_CHECK(esp_timer_stop(_command_tx_timer));
        ESP_ERROR_CHECK(esp_timer_delete(_command_tx_timer));
        _sending = false;
        return true;
    } else {
        return false;
    }
}

void SPIHandler::send_next_byte() {
    send_data(&_data[_curByteIx++], (sizeof _data / _length));
}

void SPIHandler::tx_timer_callback(void* arg) {
    SPIHandler& spi = SPIHandler::instance();

    if (spi.delete_timer_if_done()) {
        return;
    } else {
        spi.send_next_byte();
    }
}


