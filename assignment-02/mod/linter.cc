#include "linter.h"

#include <iostream>
#include <queue>
#include <string>

Linter::Linter(const std::string& str_in): NEWLINE('\n'), TAB('\t') {
    setQ(str_in);
}

void Linter::setQ(const std::string &str_in) {
    std::queue<char> tmp_q;
    for (char c : str_in) {
        tmp_q.push(c);
    }
    this->q = tmp_q;
}

std::string Linter::getQ() {
    std::string res = "";
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
        res += q.front();
        q.push(q.front());
        q.pop();
    }
    return res;
}

void Linter::print(const int& lint_status) {
    if (lint_status == 0) {
        std::cout << getQ() << std::endl;
    } else {
        std::cerr << getQ() << std::endl;
    }
}

void Linter::setError(std::string str_in) {
    setQ(str_in);
}
