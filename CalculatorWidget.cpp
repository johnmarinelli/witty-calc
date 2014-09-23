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
           mOperation = op;
           double rhs = mDisplay->getValue();
           mDisplay->clear();
           double res = performOperation(rhs);
           mDisplay->setText(std::to_string(res));

           std::cout << rhs << " " << res << " "<< op << std::endl;

        }, mOperations[i]->getOperation()));
    }
}

double CalculatorWidget::performOperation(double rhs)
{
    if(mOperation == "+") mResult += rhs;
    else if(mOperation == "-") mResult -= rhs;
    else if(mOperation == "*") mResult *= rhs;
    else if(mOperation == "/") mResult /= rhs;
    
    return mResult;
}

CalculatorWidget::CalculatorWidget(WContainerWidget* parent) : WContainerWidget(parent), mOperation(""), mResult(0)
{
    mDisplay = new CalculatorDisplay(this);
    addWidget(mDisplay);

    initNumberButtons();
    initOperationButtons();
}

CalculatorWidget::~CalculatorWidget()
{
}
