#ifndef LV3_COMPLETE_LINTER_H_
#define LV3_COMPLETE_LINTER_H_

#include <stack>
#include <string>
#include "linter.h"

class CompleteLinter : public Linter {
private:
    std::stack<char> stk;
public:
    explicit CompleteLinter(const std::string& str_in) : Linter(str_in) {}
    void lint() override;
};

#endif // LV3_COMPLETE_LINTER_H_
