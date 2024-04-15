#include <iostream>
#include <string>

#include "linter.h"
#include "linter_lv1.h"

using namespace std;

int main() {
    string in;
    getline(cin, in);

    Linter* lv1 = new LinterLv1(in);
    lv1->lint();
    lv1->print();
    delete lv1;

    return 0;
}
