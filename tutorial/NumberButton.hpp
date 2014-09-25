#ifndef NumberButton_hpp
#define NumberButton_hpp

#include <Wt/WContainerWidget>
#include <Wt/WPushButton>

using namespace Wt;

class NumberButton : public WPushButton
{
private:
    double mValue;

public:
    NumberButton(int val, WContainerWidget* parent=0);
    
    char getValue();
};

#endif
