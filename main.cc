#include <iostream>
#include <string>

#include "linter.h"
#include "lv1_stack_linter.h"
#include "lv2_queue_linter.h"
#include "lv3_complete_linter.h"

using namespace std;

int main(int argc, char *argv[]) {
    string in;
    getline(cin, in);

    if (argc < 2) {
        cerr << "error: level not provided" << endl;
        return 1;
    }

    Linter* linter;
    switch (argv[1][0]) {
        case '1':
            linter = new StackLinter(in);
            break;
        case '2':
            linter = new QueueLinter(in);
            break;
        case '3':
            linter = new CompleteLinter(in);
            break;
        default:
            cerr << "error: undefined level '" << argv[1][0] << "'" << endl;
            return 1;
    }

    linter->lint();
    linter->print();
    delete linter;

    return 0;
}
