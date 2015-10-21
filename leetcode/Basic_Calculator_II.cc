class Solution {
public:
    int calculate(string s) {
        unordered_map<char, int> priority{
            {'*', 2}, {'/', 2}, {'-', 1}, {'+', 0}
        };
        vector<int> nums;
        vector<char> operators;
        string str;
        for (auto &&c : s) {
            if (' ' == c)
                continue;
            if (isdigit(c))
                str += c;
            else {
                if (operators.empty() || priority[c] > priority[operators.back()]) {
                    operators.push_back(c);
                    nums.push_back(stoi(str));
                }
                else {
                    int temp(stoi(str));
                    while (!operators.empty() && priority[c] <= priority[operators.back()]) {
                        temp = operation(nums.back(), operators.back(), temp);
                        nums.pop_back();
                        operators.pop_back();
                    }
                    nums.push_back(temp);
                    operators.push_back(c);
                }
                str.clear();
            }
        }
        nums.push_back(stoi(str));
        while (!operators.empty()) {
            auto temp(operation(nums[nums.size() - 2], operators.back(), nums.back()));
            nums.pop_back();
            nums.pop_back();
            nums.push_back(temp);
            operators.pop_back();
        }
        return nums.back();
    }
    
private:
    int operation(int a, char c, int b) {
        switch (c) {
            case '*': return a * b;
            case '/': return a / b;
            case '-': return a - b;
            case '+': return a + b;
        }
    }
};

// !!!! awesome solution
class Solution {
public:
    int calculate(string s) {
        int ret(0), operand(0);
        char op;
        istringstream input('+' + s + '+');
        while (input >> op) {
            if ('+' == op or '-' == op) {
                ret += operand;
                input >> operand;
                operand *= (44 - op); // operand *= ('+' == op ? 1 : -1);
            }
            else {
                int temp;
                input >> temp;
                if ('*' == op)
                    operand *= temp;
                else
                    operand /= temp;
            }
        }
        return ret;
    }
};
