#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "driver/spi_master.h"

class SPIHandler {
public:
    SPIHandler();
    ~SPIHandler();

    void startup();
    void init();
    void send_cmd(const char *data, const uint8_t len);
    void send_data(const char *data, int size);
    bool delete_timer_if_done();
    void send_next_byte();

    static void tx_timer_callback(void* arg);

    spi_device_handle_t _spi;
    esp_timer_handle_t _command_tx_timer;
    const char *_data;
    uint8_t _length;
    uint8_t _curByteIx;
    bool _sending;

    static SPIHandler& instance();
};