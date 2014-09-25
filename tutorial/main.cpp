#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WText>

#include "CalculatorWidget.hpp"

using namespace Wt;

WApplication* createApplication(const WEnvironment& env)
{
    WApplication* app = new WApplication(env);
    WApplication::instance()->useStyleSheet("app-style.css");
    CalculatorWidget* calculator = new CalculatorWidget(app->root());
    return app;
}

int main(int argc, char* args[])
{
    return WRun(argc, args, &createApplication);
}
