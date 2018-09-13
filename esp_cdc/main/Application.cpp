#include "Application.h"

Application::Application()
: _A2DPHandler(A2DPHandler::instance())
, _CDChanger(CDChanger::instance())
, _CarRadio(CarRadio::instance())
{
    _A2DPHandler.startup();
    _CDChanger.startup();
}

Application::~Application() {
    
}