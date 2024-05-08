#include <iostream> 
#include <stack>

using namespace std;

int main() {
    stack<int> s;

    s.push(21);
    s.push(22);
    s.push(24);
    s.push(25);
    s.push(26);

    s.pop();
    s.pop();

    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}
