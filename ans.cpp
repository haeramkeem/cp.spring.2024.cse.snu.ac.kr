#include <iostream>
#include <string>
#include <stack>
#include <queue>

#define NEWLINE '\n'
#define TAB '\t'

using namespace std;

class Linter {
    protected:
        queue<char> *q;
    public:
        Linter(string str_in) {
            this->q = new queue<char>();
            for (string::iterator it = str_in.begin(); it < str_in.end(); it++) {
                q->push(*it);
            }
        }

        void print() {
            int q_size = q->size();
            for (int i = 0; i < q_size; i++) {
                cout << q->front();
                q->push(q->front());
                q->pop();
            }
        }

        virtual void lint() = 0;
};

class LinterLv1: public Linter {
    public:
        LinterLv1(string str_in): Linter(str_in) {}

        void lint() {
            stack<char> stk;
            int q_size = q->size();

            for (int i = 0; i < q_size; i++) {
                char cur = q->front();
                switch (cur) {
                    case '{':
                        stk.push(cur);
                        q->push(cur);
                        q->push(NEWLINE);
                        break;
                    case ';':
                        q->push(cur);
                        q->push(NEWLINE);
                        break;
                    case '}':
                        stk.pop();
                        q->push(cur);
                        break;
                    default:
                        if (q->back() == NEWLINE)
                            for (int j = 0; j < stk.size(); j++)
                                q->push(TAB);
                        q->push(cur);
                }
                q->pop();
            }
        }
};

int main() {
    string in;
    getline(cin, in);

    Linter *lv1 = new LinterLv1(in);
    lv1->lint();
    lv1->print();

    return 0;
}
