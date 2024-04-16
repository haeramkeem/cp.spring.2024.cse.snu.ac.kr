#ifndef LINTER_H_
#define LINTER_H_

#include <iostream>
#include <string>
#include <queue>

class Linter {
private:
    std::string err;
protected:
    const char TAB;
    const char NEWLINE;
    std::queue<char> q;
public:
    explicit Linter(const std::string& str_in);
    void print();
    void setError(const std::string& err);
    virtual ~Linter() {}
    virtual int lint() = 0;
};

#endif // LINTER_H_
