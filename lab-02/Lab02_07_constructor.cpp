#include <iostream>
#include <string>

using namespace std;

class Chicken {
    public:
        Chicken(string arg) {
            name = arg;
            cout << name << " created." << endl;
        }

        string name;
        void print_name() {
            cout << "I am " << name << endl;
        }
};

int main() {
    Chicken chicken("KFC");
    chicken.print_name();
    return 0;
}
