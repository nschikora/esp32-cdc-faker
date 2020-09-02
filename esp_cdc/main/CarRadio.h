#include "SPIHandler.h"
#include "RadioCommandReceiver.h"

class CarRadio {
public:
    static CarRadio& getInstance() {
        static CarRadio instance;
        return instance;
    }
    void init();

    SPIHandler& _radio_spi;
    RadioCommandReceiver& _radio_nec;
    esp_timer_handle_t _ping_timer;

    static CarRadio& instance();
    static void ping_timer_callback(void* arg);

private:
    CarRadio();
    ~CarRadio();
    CarRadio(CarRadio const&); // Don't Implement
    void operator=(CarRadio const&); // Don't implement
};