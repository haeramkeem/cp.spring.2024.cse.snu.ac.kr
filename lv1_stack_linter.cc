#include "lv1_stack_linter.h"

int StackLinter::lint() {
    int q_size = q.size();
    int i_size = 0;

    for (int i = 0; i < q_size; i++) {
        char cur = q.front();
        switch (cur) {
            case ',':
                q.push(cur);
                q.push(NEWLINE);
                q.pop();
                break;
            case '[':
            case '{':
                stk.push(cur);
                i_size++;
                q.push(cur);
                q.push(NEWLINE);
                q.pop();
                break;
            case ']':
            case '}':
                if (stk.empty() || (stk.top() != '{' && cur == '}') || (stk.top() != '[' && cur == ']')) {
                    setError("error");
                    return 1;
                }
                stk.pop();
                i_size--;
                for (int j = 0; j < i_size; j++) {
                    q.push(TAB);
                }
                q.push(cur);
                q.pop();
                if (q.front() != ',') {
                    q.push(NEWLINE);
                }
                break;
            default:
                if (q.back() == NEWLINE) {
                    for (int j = 0; j < i_size; j++) {
                        q.push(TAB);
                    }
                }
                q.push(cur);
                q.pop();
        }
    }

    if (!stk.empty()) {
        setError("error");
        return 1;
    }

    return 0;
}
