#include "lv2_queue_linter.h"

int QueueLinter::lint() {
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
                q_stk.push(cur);
                i_size++;
                q.push(cur);
                q.push(NEWLINE);
                q.pop();
                break;
            case ']':
            case '}':
                for (int j = 0; j < q_stk.size() - 1; j++) {
                    q_stk.push(q_stk.front());
                    q_stk.pop();
                }
                if (q_stk.empty() || (q_stk.front() != '{' && cur == '}') || (q_stk.front() != '[' && cur == ']')) {
                    setError();
                    return 1;
                }
                q_stk.pop();
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

    if (!q_stk.empty()) {
        setError();
        return 1;
    }

    return 0;
}
