class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> s;
        unordered_set<string> operators{"+", "-", "*", "/"};
        for (auto &&token : tokens) {
            if (operators.find(token) == operators.end())
                s.push_back(stoi(token));
            else {
                auto b(s.back());
                s.pop_back();
                auto a(s.back());
                s.pop_back();
                if (token == "+")
                    s.push_back(a + b);
                else if (token == "-")
                    s.push_back(a - b);
                else if (token == "*")
                    s.push_back(a * b);
                else
                    s.push_back(a / b);
            }
        }
        return s.back();
    }
};

// Optimized solution
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> s;
        for (auto &&token : tokens) {
            if (token.length() > 1 || isdigit(token.front()))
                s.push_back(stoi(token));
            else {
                auto b(s.back());
                s.pop_back();
                auto a(s.back());
                s.pop_back();
                switch (token.front()) {
                    case '+': s.push_back(a + b); break;
                    case '-': s.push_back(a - b); break;
                    case '*': s.push_back(a * b); break;
                    case '/': s.push_back(a / b); break;
                    default: break;
                }
            }
        }
        return s.back();
    }
};
