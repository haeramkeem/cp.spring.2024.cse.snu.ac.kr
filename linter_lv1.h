#ifndef HW_CP24S_CSE_SNU_AC_KR_LINTER_LV1_H_
#define HW_CP24S_CSE_SNU_AC_KR_LINTER_LV1_H_

#include <string>
#include "linter.h"

class LinterLv1 : public Linter {
public:
    explicit LinterLv1(const std::string& str_in) : Linter(str_in) {}
    void lint() override;
};

#endif // HW_CP24S_CSE_SNU_AC_KR_LINTER_LV1_H_
