#include "lv2_queue_linter.h"

const char NEWLINE = '\n';
const char TAB = '\t';

int QueueLinter::lint() {
    int q_size = q.size();

    for (int i = 0; i < q_size; i++) {
        char cur = q.front();
        switch (cur) {
            case '{':
                q_stk.push(cur);
                q.push(cur);
                q.push(NEWLINE);
                break;
            case ';':
                q.push(cur);
                q.push(NEWLINE);
                break;
            case '}':
                for (int j = 0; j < q_stk.size() - 1; j++) {
                    q_stk.push(q_stk.front());
                    q_stk.pop();
                }
                q_stk.pop();
                for (int j = 0; j < q_stk.size(); j++) {
                    q.push(TAB);
                }
                q.push(cur);
                q.push(NEWLINE);
                break;
            default:
                if (!q_stk.empty() && q.back() == NEWLINE) {
                    for (int j = 0; j < q_stk.size(); j++) {
                        q.push(TAB);
                    }
                }
                q.push(cur);
        }
        q.pop();
    }
    return 0;
}
