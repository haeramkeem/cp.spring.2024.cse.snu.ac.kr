#include "lv1_stack_linter.h"

int StackLinter::lint() {
    int q_size = q.size();
    int i_size = 0;

    for (int i = 0; i < q_size; i++) {
        char cur = q.front();
        switch (cur) {
            case '(':
            case '{':
            case '[':
                for (int j = 0; j < i_size; j++) {
                    q.push(TAB);
                }
                q.push(cur);
                q.push(NEWLINE);
                i_size++;
                stk.push(cur);
                q.pop();
                break;
            case ')':
            case '}':
            case ']':
                if (
                    stk.empty()
                    || (stk.top() != '{' && cur == '}')
                    || (stk.top() != '[' && cur == ']')
                    || (stk.top() != '(' && cur == ')')
                ) {
                    setError();
                    return 1;
                }
                stk.pop();
                i_size--;
                for (int j = 0; j < i_size; j++) {
                    q.push(TAB);
                }
                q.push(cur);
                q.push(NEWLINE);
                q.pop();
                break;
        }
    }

    if (!stk.empty()) {
        setError();
        return 1;
    }

    return 0;
}
