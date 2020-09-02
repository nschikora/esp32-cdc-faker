#include "Application.h"

Application::Application()
: _A2DPHandler(A2DPHandler::instance())
, _CDChanger(CDChanger::instance())
, _CarRadio(CarRadio::getInstance())
{
    _A2DPHandler.startup();
    _CDChanger.startup();
    _CarRadio.init();
}

Application::~Application() {
    
}