#include <stack>
#include <string>
#include <sstream>

using namespace std;

    int calculate(string s) {
        int operand(0);
        stack<long> operands;
        stack<char> ops;
        int b(0);
        char op;
        for (auto &&c : s) {
            if (' ' == c)
                continue;
            else if (isalnum(c)) {
                b = b * 10 + c - '0';
                continue;
            }
            else if ('(' == c) {
                operands.push(LONG_MIN);
                continue;
            }
            else if ('+' == c || '-' == c) {
                if (!ops.empty()) {
                    op = ops.top();
                    ops.pop();
                }
                ops.push(c);
            }
            else {
                b = operands.top();
                operands.pop();
                operands.pop();
                if (!ops.empty()) {
                    op = ops.top();
                    ops.pop();
                }
            }
            if (operands.empty() || operands.top() == LONG_MIN)
                operands.push(b);
            else {
                auto a(operands.top());
                operands.pop();
                switch (op) {
                    case '+': operands.push(a + b); break;
                    case '-': operands.push(a - b); break;
                }
            }
	    b = 0;
        }
        return operands.top();
    }

int main() {
  auto ret(calculate("(1+(4+5+2)-3)+(6+8)"));
  return 0;
}
