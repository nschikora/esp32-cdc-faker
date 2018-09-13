#include "i2sHandler.h"
#include "A2DPHandler.h"
#include "CDChanger.h"
#include "CarRadio.h"

class Application {
public:
    Application();
    ~Application();

private:
    i2sHandler _i2sHandler;
    A2DPHandler _A2DPHandler;
    CDChanger _CDChanger;
    CarRadio _CarRadio;
};