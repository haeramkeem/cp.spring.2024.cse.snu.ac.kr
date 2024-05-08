#include <iostream>
#include <queue>
 
using namespace std;

int main() {
    queue<int> q;
 
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
 
    q.pop();
 
    cout << "Queue: ";
    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}
