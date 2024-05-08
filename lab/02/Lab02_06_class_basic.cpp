#include <iostream>
#include <string>

using namespace std;

class Chicken {
    public:
        string name = "KFC";
        void print_name() {
            cout << "I am " << name << endl;
        }
};

int main() {
    Chicken chicken;
    chicken.print_name();
    return 0;
}
