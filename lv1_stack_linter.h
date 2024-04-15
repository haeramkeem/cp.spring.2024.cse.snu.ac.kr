#ifndef HW_CP24S_CSE_SNU_AC_KR_LINTER_LV1_H_
#define HW_CP24S_CSE_SNU_AC_KR_LINTER_LV1_H_

#include <stack>
#include <string>
#include "linter.h"

class StackLinter : public Linter {
private:
    std::stack<char> stk;
public:
    explicit StackLinter(const std::string& str_in) : Linter(str_in) {}
    void lint() override;
};

#endif // HW_CP24S_CSE_SNU_AC_KR_LINTER_LV1_H_
