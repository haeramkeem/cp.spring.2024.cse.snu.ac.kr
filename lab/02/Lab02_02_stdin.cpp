#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;

    // Method 1) using `getline`
    getline(cin, input);
    cout << input << endl;

    // Method 2) using `cin`
    cin >> input;
    cout << input << endl;

    return 0;
}
