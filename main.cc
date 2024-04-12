#include <iostream>
#include <string>
#include <stack>
#include <queue>

#include "linter.h"

#define NEWLINE '\n'
#define TAB '\t'

using namespace std;

class LinterLv1 : public Linter {
public:
    LinterLv1(const string& str_in) : Linter(str_in) {}

    void lint() {
        stack<char> stk;
        int q_size = q.size();

        for (int i = 0; i < q_size; i++) {
            char cur = q.front();
            switch (cur) {
                case '{':
                    stk.push(cur);
                    q.push(cur);
                    q.push(NEWLINE);
                    break;
                case ';':
                    q.push(cur);
                    q.push(NEWLINE);
                    break;
                case '}':
                    stk.pop();
                    q.push(cur);
                    break;
                default:
                    if (!stk.empty() && q.back() == NEWLINE) {
                        for (int j = 0; j < stk.size(); j++) {
                            q.push(TAB);
                        }
                    }
                    q.push(cur);
            }
            q.pop();
        }
    }
};

int main() {
    string in;
    getline(cin, in);

    Linter* lv1 = new LinterLv1(in);
    lv1->lint();
    lv1->print();
    delete lv1;

    return 0;
}
