#include "OperationButton.hpp"

OperationButton::OperationButton(std::string op, WContainerWidget* parent) : WPushButton(op, parent), mOperation(op)
{
}

std::string OperationButton::getOperation()
{
    std::cout << "OperationButton::getOperation() " << mOperation << std::endl;
    return mOperation;
}
