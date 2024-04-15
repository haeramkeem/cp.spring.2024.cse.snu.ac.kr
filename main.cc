#include <iostream>
#include <string>

#include "linter.h"
#include "lv1_stack_linter.h"

using namespace std;

int main() {
    string in;
    getline(cin, in);

    Linter* lv1 = new StackLinter(in);
    lv1->lint();
    lv1->print();
    delete lv1;

    return 0;
}
