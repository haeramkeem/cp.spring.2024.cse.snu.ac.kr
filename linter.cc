#include "linter.h"

#include <iostream>
#include <string>

Linter::Linter(const std::string& str_in) {
    for (char c : str_in) {
        q.push(c);
    }
    err = "";
}

void Linter::print() {
    if (err != "") {
        std::cerr << err << std::endl;
        return;
    }
    int q_size = q.size();
    for (int i = 0; i < q_size; ++i) {
        std::cout << q.front();
        q.push(q.front());
        q.pop();
    }
    std::cout << std::endl;
}

void Linter::setError(const std::string& err) {
    this->err = err;
}
