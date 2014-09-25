#include "OperationButton.hpp"

OperationButton::OperationButton(std::string op, WContainerWidget* parent) : WPushButton(op, parent), mOperation(op)
{
    this->addStyleClass("operation-button");
}

std::string OperationButton::getOperation()
{
    return mOperation;
}
