#include <iostream>
#include <string>

using namespace std;

class Chicken {
    public:
        Chicken() {
            name = "KFC";
            cout << name << " created with default constructor." << endl;
        }

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
    Chicken chicken;
    chicken.print_name();

    Chicken dfc("DFC, Delicious Fried Chicken");
    dfc.print_name();
    return 0;
}
