#include <iostream>

using namespace std;

int foo() {
  cout << "Foo!" << endl;
  return 0;
}

int bar() {
  cout << "Bar!" << endl;
  return 0;
}

int main() {
  foo();
  bar();
}
