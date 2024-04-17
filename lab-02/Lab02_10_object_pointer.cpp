#include <iostream>
#include <string>

using namespace std;

class Chicken {
    public:
        Chicken() {
            name = "KFC";
            cout << name << " created with default constructor." << endl;
        }

        Chicken(string name) {
            this->name = name;
            cout << name << " created." << endl;
        }

        ~Chicken() {
            cout << name << " says: I'll be back" << endl;
        }

        string name;
        void print_name() {
            cout << "I am " << name << endl;
        }
};

int main() {
    Chicken *chicken = new Chicken();
    chicken->print_name();
    delete chicken;

    Chicken dfc("DFC, Delicious Fried Chicken");
    dfc.print_name();

    return 0;
}
