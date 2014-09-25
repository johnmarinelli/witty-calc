#include "NumberButton.hpp"

NumberButton::NumberButton(int val, WContainerWidget* parent) : WPushButton(std::to_string(val), parent), mValue(val)
{
    this->addStyleClass("number-button");
}

char NumberButton::getValue()
{
    return std::to_string(mValue)[0];
}
