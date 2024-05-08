#ifndef LV2_QUEUE_LINTER_H_
#define LV2_QUEUE_LINTER_H_

#include <queue>
#include <string>
#include "linter.h"

class QueueLinter : public Linter {
private:
    std::queue<char> q_stk;
public:
    explicit QueueLinter(const std::string& str_in) : Linter(str_in) {}
    int lint() override;
};

#endif // LV2_QUEUE_LINTER_H_
