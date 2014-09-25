#ifndef CalculatorDisplay_hpp
#define CalculatorDisplay_hpp

#include <Wt/WContainerWidget>
#include <Wt/WIntValidator>
#include <Wt/WLineEdit>

using namespace Wt;

class CalculatorDisplay : public WLineEdit
{
private:
    std::string mValue;
    WIntValidator* mValidator;
    
public:
    CalculatorDisplay(WContainerWidget* parent=0);

    void push(char num);
    double getValue();
    void clear();
    
    ~CalculatorDisplay();
};

#endif
