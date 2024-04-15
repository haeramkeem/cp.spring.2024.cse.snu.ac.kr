#include "linter_lv1.h"

#include <stack>

const char NEWLINE = '\n';
const char TAB = '\t';

void LinterLv1::lint() {
    std::stack<char> stk;
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
                for (int j = 0; j < stk.size(); j++) {
                    q.push(TAB);
                }
                q.push(cur);
                q.push(NEWLINE);
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
