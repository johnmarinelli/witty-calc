#include "NumberButton.hpp"

NumberButton::NumberButton(int val, WContainerWidget* parent) : WPushButton(std::to_string(val), parent), mValue(val)
{    
}

/*
*   This is used to push the number into the display as a string
*/
char NumberButton::getValue()
{
    return std::to_string(mValue)[0];
}
