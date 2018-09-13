#include "CarRadio.h"

static char RADIO_CMD_ENABLE_CDC[] = { 0x74, 0xBE, 0xFE, 0xFF, 0xFF, 0xFF, 0x8F, 0x7C };
// { 0x74, 0xD9, 0xFE, 0xFF, 0xFF, 0xFF, 0xCF, 0x7C }
// { 0x34, 0xBE, 0xFF, 0xFF, 0xFF, 0xFF, 0xCF, 0x3C }

CarRadio::CarRadio() {
    _radio_spi.startup();
    _radio_nec.startup();
}

CarRadio::~CarRadio() {

}

void CarRadio::init() {
    _radio_spi.send_cmd(RADIO_CMD_ENABLE_CDC, 8);
}

CarRadio& CarRadio::instance() {
    CarRadio instance;
    return instance;
}