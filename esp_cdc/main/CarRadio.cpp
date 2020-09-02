#include "CarRadio.h"

// static char RADIO_CMD_ENABLE_CDC[] = { 0x74, 0xBE, 0xFE, 0xFF, 0xFF, 0xFF, 0x8F, 0x7C };
static char RADIO_CMD_ENABLE_CDC[] = { 0x74, 0xBE, 0xFE, 0xFF, 0xFF, 0xFF, 0xCF, 0x7C };
// static char RADIO_CMD_ENABLE_CDC[] = { 0x34, 0xBE, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x3C };
// static char RADIO_CMD_ENABLE_CDC[] = { 0x74, 0xD9, 0xFE, 0xFF, 0xFF, 0xFF, 0xCF, 0x7C }


CarRadio::CarRadio() 
: _radio_spi(SPIHandler::getInstance())
, _radio_nec(RadioCommandReceiver::getInstance())
{
    _radio_spi.startup();
    _radio_nec.startup();
}

CarRadio::~CarRadio() {

}

void CarRadio::init() {
    esp_timer_create_args_t tx_timer_args = {};
    tx_timer_args.callback = &CarRadio::ping_timer_callback;
    tx_timer_args.name = "cr_ping";

    ESP_ERROR_CHECK(esp_timer_create(&tx_timer_args, &_ping_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(_ping_timer, 10000));
    
}

void CarRadio::ping_timer_callback(void* arg) {
    CarRadio& cr = CarRadio::getInstance();
    cr._radio_spi.send_cmd(RADIO_CMD_ENABLE_CDC, 8);
}

