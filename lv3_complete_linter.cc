#include "lv3_complete_linter.h"
#include <stack>

const char NEWLINE = '\n';
const char TAB = '\t';

void CompleteLinter::lint() {
    int q_size = q.size();
    bool disable_newline = false;

    for (int i = 0; i < q_size; i++) {
        char cur = q.front();
        switch (cur) {
            case '{':
                stk.push(cur);
                q.push(cur);
                if (!disable_newline)
                    q.push(NEWLINE);
                break;
            case ';':
                q.push(cur);
                if (!disable_newline)
                    q.push(NEWLINE);
                break;
            case '}':
                stk.pop();
                for (int j = 0; j < stk.size(); j++)
                    q.push(TAB);
                q.push(cur);
                if (!disable_newline)
                    q.push(NEWLINE);
                break;
            case '(':
                disable_newline = true;
                q.push(cur);
                break;
            case ')':
                disable_newline = false;
                q.push(cur);
                break;
            default:
                if (!stk.empty() && q.back() == NEWLINE) {
                    for (int j = 0; j < stk.size(); j++)
                        q.push(TAB);
                }
                q.push(cur);
        }
        q.pop();
    }
}
