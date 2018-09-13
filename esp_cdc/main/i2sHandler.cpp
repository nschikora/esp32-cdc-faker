#include "freertos/FreeRTOS.h"
#include "driver/i2s.h"

#include "config.h"
#include "i2sHandler.h"

i2sHandler::i2sHandler() {
    i2s_config_t i2s_config = {
        (i2s_mode_t)(i2s_mode_t::I2S_MODE_MASTER | i2s_mode_t::I2S_MODE_TX),    // mode
        44100,                                                                  // sample rate
        CONFIG_I2S_BITS_PER_SAMPLE,                                             // bit depth
        CONFIG_I2S_CHANNEL_FORMAT,                                              // channel format
        CONFIG_I2S_COMM_FORMAT,                                                 // communication format
        ESP_INTR_FLAG_LEVEL1,                                                   // interrup level
        6,                                                                      // DMA buffer count
        60                                                                      // DMA buffer length
    };

    i2s_driver_install(CONFIG_I2S_PORT, &i2s_config, 0, NULL);

    i2s_pin_config_t pin_config = {
        CONFIG_I2S_BCK_PIN,     // bit clock pin
        CONFIG_I2S_LRCK_PIN,    // word select clock pin
        CONFIG_I2S_DATA_PIN,    // data out pin
        -1                      // data in pin (unused)
    };

    i2s_set_pin(CONFIG_I2S_PORT, &pin_config);
}

i2sHandler::~i2sHandler() {

}