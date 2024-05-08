#include <iostream>
#include <deque>
 
using namespace std;

int main() {
    std::deque<int> d = {7, 5, 16, 8};
 
    d.push_front(13);
    d.pop_back();
    d.push_back(25);
 
    cout << "Deque: ";
    while (!d.empty()) {
        cout << d.front() << ' ';
        d.pop_front();
    }
    cout << endl;
}
