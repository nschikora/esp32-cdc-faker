#include "SPIHandler.h"
#include "RadioCommandReceiver.h"

class CarRadio {
public:
    CarRadio();
    ~CarRadio();

    void init();

    SPIHandler _radio_spi;
    RadioCommandReceiver _radio_nec;

    static CarRadio& instance();
};