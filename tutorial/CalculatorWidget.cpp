#include "CalculatorWidget.hpp"

#include <Wt/WBreak>

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
            mOperation = op;
            double val = mDisplay->getValue();
            setEquation(val);
            mDisplay->clear();
        }, mOperations[i]->getOperation()));
    }
}

void CalculatorWidget::setEquation(double val)
{
    if(mLHS == 0.0) mLHS = val;
    else mRHS = val;
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

CalculatorWidget::CalculatorWidget(WContainerWidget* parent) : WContainerWidget(parent), mOperation("+"), mLHS(0), mRHS(0)
{
    mDisplay = new CalculatorDisplay(this);
    new WBreak(this);

    initNumberButtons();

    new WBreak(this);
    initOperationButtons();

    mEquals = new WPushButton("=", this);
    mEquals->clicked().connect(std::bind ([&] () { 
        double val = mDisplay->getValue();
        setEquation(val);
        mDisplay->clear();
        mDisplay->setText(std::to_string(performOperation()));
    }));

    mEquals->addStyleClass("operation-button");
}

