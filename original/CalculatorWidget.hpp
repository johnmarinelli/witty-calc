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
    enum { opCount = 4 };

    NumberButton* mNumbers[numberCount];
    OperationButton* mOperations[opCount];
    WPushButton* mDecimal;
    WPushButton* mEquals;
    WPushButton* mClear;
    CalculatorDisplay* mDisplay;

    std::string mOperation;
    double mLHS;
    double mRHS;
    double mResult;

    void initNumberButtons();
    void initOperationButtons();

    void setEquation(double val);

    double performOperation();

public:
    CalculatorWidget(WContainerWidget* parent);

    ~CalculatorWidget();    
};

#endif
