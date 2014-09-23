#ifndef CalculatorWidget_hpp
#define CalculatorWidget_hpp

#include <Wt/WContainerWidget>

#include "CalculatorDisplay.hpp"
#include "NumberButton.hpp"
#include "OperationButton.hpp"

using namespace Wt;

class CalculatorWidget : public WContainerWidget
{
private:
    enum { numberCount = 10 };
    enum { opCount = 5 };

    NumberButton* mNumbers[numberCount];
    OperationButton* mOperations[opCount];
    CalculatorDisplay* mDisplay;

    std::string mOperation;
    double mResult;

    void initNumberButtons();
    void initOperationButtons();

    double performOperation(double rhs);

public:
    CalculatorWidget(WContainerWidget* parent);

    ~CalculatorWidget();    
};

#endif
