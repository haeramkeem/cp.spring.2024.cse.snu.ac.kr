#ifndef HW_CP24S_CSE_SNU_AC_KR_LINTER_H_
#define HW_CP24S_CSE_SNU_AC_KR_LINTER_H_

#include <iostream>
#include <string>
#include <queue>

class Linter {
protected:
    std::queue<char> q;

public:
    explicit Linter(const std::string& str_in);
    void print();
    virtual ~Linter() {}
    virtual void lint() = 0;
};

#endif // HW_CP24S_CSE_SNU_AC_KR_LINTER_H_
