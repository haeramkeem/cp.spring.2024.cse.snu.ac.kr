# C++ Exam 01

```cpp
#include <iostream>

using namespace std;

class Parent {
 public:
  virtual void pubDisplay() {
    cout << "A";
  }
 private:
  virtual void privDisplay() {
    cout << "B";
  }
 protected:
  virtual void protDisplay() {
    cout << "C";
  }
};

class Child : public Parent {
 public:
  void pubDisplay() {
    cout << "a";
  }
  void privDisplay() {
    cout << "b";
  }
  void protDisplay() {
    cout << "c";
  }
};

int main() {
  Parent *c = new Child();
  c->pubDisplay();
  c->privDisplay();
  c->protDisplay();
  cout << endl;
  delete c;
  return 0;
}
```

- When compile and run the code above, choose <u>all</u> the expected behaviours below.
  1. The code is compiled successfully, and prints `abc`.
  2. The code is compiled successfully, and prints `abc`.
  3. The code is compiled successfully, and prints `aBc`.
  4. When delete the line `c->privDisplay();`, the code is compiled successfully and prints `ac`.
  5. When delete the line `c->privDisplay();`, the code is compiled successfully and prints `AC`.
  6. When delete the line `c->privDisplay();` and `c->protDisplay();`, the code is compiled successfully and prints `a`.
  7. When delete the line `c->privDisplay();` and `c->protDisplay();`, the code is compiled successfully and prints `A`.
