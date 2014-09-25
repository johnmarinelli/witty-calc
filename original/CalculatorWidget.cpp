#include "CalculatorWidget.hpp"

void CalculatorWidget::initNumberButtons()
{
    for(int i = 0; i < numberCount; ++i){
        mNumbers[i] = new NumberButton(i, this);
        addWidget(mNumbers[i]);
        mNumbers[i]->clicked().connect(std::bind([&] (char num) {
            mDisplay->push(num);
        }, mNumbers[i]->getValue()));
    }
}

void CalculatorWidget::initOperationButtons()
{
    mOperations[0] = new OperationButton("+", this);
    mOperations[1] = new OperationButton("-", this);
    mOperations[2] = new OperationButton("*", this);
    mOperations[3] = new OperationButton("/", this);

    for(int i = 0; i < opCount; ++i){
        addWidget(mOperations[i]);

        mOperations[i]->clicked().connect(std::bind([=] (std::string op) {
            /* save operation in mOperation member variable */
            mOperation = op;
            
            /* retrieve value from mDisplay before we clear it for next number */
            double val = mDisplay->getValue();           
            setEquation(val);
            mDisplay->clear();
        }, mOperations[i]->getOperation()));
    }
}

void CalculatorWidget::setEquation(double val)
{
    /* check to see if we need to set rhs */
    if(mLHS != 0.0) mRHS = val;
    else mLHS = val;
}

double CalculatorWidget::performOperation()
{
    if(mOperation == "+") mResult = mLHS + mRHS;
    else if(mOperation == "-") mResult = mLHS - mRHS;
    else if(mOperation == "*") mResult = mLHS * mRHS;
    else if(mOperation == "/") if(mRHS != 0) mResult = mLHS / mRHS;
    mLHS = mResult;
    mRHS = 0.0;

    return mResult;
}

CalculatorWidget::CalculatorWidget(WContainerWidget* parent) : WContainerWidget(parent), mOperation("+"), mLHS(0), mRHS(0), mResult(0)
{
    mDisplay = new CalculatorDisplay(this);
    addWidget(mDisplay);

    initNumberButtons();
    
    mDecimal = new WPushButton(".", this);
    mDecimal->clicked().connect(std::bind([&] () {
        mDisplay->push('.');
    }));

    addWidget(mDecimal);
    initOperationButtons();

    mEquals = new WPushButton("=", this);
    mEquals->clicked().connect(std::bind([&] () {
        double val = mDisplay->getValue();
        mDisplay->clear();
        setEquation(val);
        mDisplay->setText(std::to_string(performOperation()));
    }));

    addWidget(mEquals);

    mClear = new WPushButton("Clear", this);
    mClear->clicked().connect(std::bind([&] () {
        mLHS = mRHS = 0.0;
        mResult = 0;
        mDisplay->clear();
    }));

    addWidget(mClear);
}

CalculatorWidget::~CalculatorWidget()
{
}
