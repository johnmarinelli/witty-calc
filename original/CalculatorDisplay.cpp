#include "CalculatorDisplay.hpp"

CalculatorDisplay::CalculatorDisplay(WContainerWidget* parent) : WLineEdit(parent), mValue(""), mValidator(new WIntValidator())
{
    mValidator->setMandatory(true);
    this->setValidator(mValidator);
}

void CalculatorDisplay::push(char num)
{
    mValue.push_back(num);
    setText(mValue);
}

double CalculatorDisplay::getValue()
{
    return std::stod(mValue);
}

void CalculatorDisplay::clear()
{
    mValue = "";
    setText("");
}

CalculatorDisplay::~CalculatorDisplay()
{
    delete mValidator;
    mValidator = nullptr;
}
