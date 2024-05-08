#include <iostream>
#include <string>

using namespace std;

void print_arg(string arg1, string arg2 = "with default") {
    cout << arg1 << " " << arg2  << endl;
}

int main() {
    print_arg("Print this");
    print_arg("Print this", "and this");

    return 0;
}
