class Solution {
public:
    int calculate(string s) {
        stack<int> operands, operators;
        int sign(1), res(0), num(0);
        for (auto &&c : s) {
            if (isdigit(c))
                num = num * 10 + c - '0';
            else {
                res += sign * num;
		// reset num
                num = 0;
                switch (c) {
                    case '+': sign = 1; break;
                    case '-': sign = -1; break;
                    case '(': {
                        operands.push(res);
                        operators.push(sign);
			// reset res and sign
                        res = 0;
                        sign = 1;
                    }
                    break;
                    case ')': {
                        if (operators.empty())
                            break;
                        res = operands.top() + operators.top() * res;
                        operands.pop();
                        operators.pop();
                    }
                    break;
                    default: break;
                }
            }
        }
	// case: 1, (1 + 1) - 1
        res += sign * num;
        return res;
    }
};
