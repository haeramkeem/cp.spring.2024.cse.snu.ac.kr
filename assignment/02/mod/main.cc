#include <iostream>
#include <string>

#include "linter.h"
#include "lv1_stack_linter.h"
#include "lv2_queue_linter.h"

int main() {
    std::cout << "Input: ";
    std::string in;
    getline(std::cin, in);

    std::cout << "----- StackLinter -----" << std::endl;
    Linter* stk_linter = new StackLinter(in);
    int stk_lint_result = stk_linter->lint();
    stk_linter->print(stk_lint_result);
    delete stk_linter;

    std::cout << "----- QueueLinter -----" << std::endl;
    Linter* q_linter = new QueueLinter(in);
    int q_lint_result = q_linter->lint();
    q_linter->print(q_lint_result);
    delete q_linter;

    return stk_lint_result + q_lint_result;
}
