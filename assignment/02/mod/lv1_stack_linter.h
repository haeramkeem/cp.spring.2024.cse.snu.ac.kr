#ifndef LV1_STACK_LINTER_H_
#define LV1_STACK_LINTER_H_

#include <stack>
#include <string>
#include "linter.h"

class StackLinter : public Linter {
private:
    std::stack<char> stk;
public:
    explicit StackLinter(const std::string& str_in) : Linter(str_in) {}
    int lint() override;
};

#endif // LV1_STACK_LINTER_H_
