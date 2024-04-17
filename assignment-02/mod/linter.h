#ifndef LINTER_H_
#define LINTER_H_

#include <iostream>
#include <string>
#include <queue>

class Linter {
private:
    void setQ(const std::string& str_in);
    std::string getQ();
protected:
    const char TAB;
    const char NEWLINE;
    std::queue<char> q;
    void setError(std::string str_in = "error: invalid parentheses");
public:
    explicit Linter(const std::string& str_in);
    virtual ~Linter() {}
    void print(const int& lint_status);
    virtual int lint() = 0;
};

#endif // LINTER_H_
