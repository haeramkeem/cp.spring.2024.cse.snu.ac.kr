#include <iostream>
#include <string>

using namespace std;

class Chicken {
    public:
        Chicken(string name) {
            this->name = name;
        }

        void print_name() {
            cout << "I am " << name << endl;
        }

    private:
        string name;
};

int main() {
    Chicken chicken("KFC");
    chicken.print_name();

    cout << chicken.name << endl;

    return 0;
}
