#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

/**
 * Linter class
 */
#ifndef LINTER_H_
#define LINTER_H_

class Linter {
private:
    void setQ(const string& str_in);
    string getQ();
protected:
    const char TAB;
    const char NEWLINE;
    queue<char> q;
    void setError(string str_in);
public:
    explicit Linter(const string& str_in);
    virtual ~Linter() {}
    void print(const int& lint_status);
    virtual int lint() = 0;
};

#endif // LINTER_H_

Linter::Linter(const string& str_in): NEWLINE('\n'), TAB('\t') {
    setQ(str_in);
}

void Linter::setQ(const string &str_in) {
    queue<char> tmp_q;
    for (char c : str_in) {
        tmp_q.push(c);
    }
    this->q = tmp_q;
}

string Linter::getQ() {
    string res = "";
    int q_size = q.size();
    for (int i = 0; i < q_size; i++) {
        res += q.front();
        q.push(q.front());
        q.pop();
    }
    return res;
}

void Linter::print(const int& lint_status) {
    if (lint_status == 0) {
        cout << getQ() << endl;
    } else {
        cerr << getQ() << endl;
    }
}

void Linter::setError(string str_in = "error: invalid parentheses") {
    setQ(str_in);
}

/**
 * StackLinter class
 */
#ifndef LV1_STACK_LINTER_H_
#define LV1_STACK_LINTER_H_

class StackLinter : public Linter {
private:
    stack<char> stk;
public:
    explicit StackLinter(const string& str_in) : Linter(str_in) {}
    int lint() override;
};

#endif // LV1_STACK_LINTER_H_

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

/**
 * QueueLinter class
 */
#ifndef LV2_QUEUE_LINTER_H_
#define LV2_QUEUE_LINTER_H_

class QueueLinter : public Linter {
private:
    queue<char> q_stk;
public:
    explicit QueueLinter(const string& str_in) : Linter(str_in) {}
    int lint() override;
};

#endif // LV2_QUEUE_LINTER_H_

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

/**
 * main func
 */
int main() {
    cout << "Input: ";
    string in;
    getline(cin, in);

    cout << "----- StackLinter -----" << endl;
    Linter* stk_linter = new StackLinter(in);
    int stk_lint_result = stk_linter->lint();
    stk_linter->print(stk_lint_result);
    delete stk_linter;

    cout << "----- QueueLinter -----" << endl;
    Linter* q_linter = new QueueLinter(in);
    int q_lint_result = q_linter->lint();
    q_linter->print(q_lint_result);
    delete q_linter;

    return stk_lint_result + q_lint_result;
}
