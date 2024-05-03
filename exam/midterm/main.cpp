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
  // c->privDisplay();
  // c->protDisplay();
  cout << endl;
  delete c;
  return 0;
}
