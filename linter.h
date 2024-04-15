#ifndef LINTER_H_
#define LINTER_H_

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

#endif // LINTER_H_
