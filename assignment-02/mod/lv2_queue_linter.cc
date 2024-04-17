#include "lv2_queue_linter.h"

int QueueLinter::lint() {
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
                q_stk.push(cur);
                q.pop();
                break;
            case ')':
            case '}':
            case ']':
                for (int j = q_stk.size(); 1 < j; j--) {
                    q_stk.push(q_stk.front());
                    q_stk.pop();
                }
                if (
                    q_stk.empty()
                    || (q_stk.front() != '{' && cur == '}')
                    || (q_stk.front() != '[' && cur == ']')
                    || (q_stk.front() != '(' && cur == ')')
                ) {
                    setError();
                    return 1;
                }
                q_stk.pop();
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

    if (!q_stk.empty()) {
        setError();
        return 1;
    }

    return 0;
}
