#ifndef OperationButton_hpp
#define OperationButton_hpp

#include <Wt/WContainerWidget>
#include <Wt/WPushButton>

using namespace Wt;

class OperationButton : public WPushButton
{
private:
    std::string mOperation;

public:
    OperationButton(std::string op, WContainerWidget* parent=0);

    std::string getOperation();
};

#endif
