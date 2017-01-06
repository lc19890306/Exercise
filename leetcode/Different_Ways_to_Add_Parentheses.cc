// Divide-and-conquer solution - exponential time complexity
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        istringstream in(input);
        int operand;
        char op;
        operators.push_back(0);
        while (in >> operand) {
            operands.push_back(operand);
            in >> op;
            operators.push_back(op);
        }
        return compute(0, operands.size());
    }
    
private:
    vector<int> compute(int first, int last) {
        vector<int> ret;
        switch (last - first) {
            case 0: ret.push_back(0); break;
            case 1: ret.push_back(operands[first]); break;
            default: {
                for (int i(first + 1); i < last; ++i) {
                    auto left(compute(first, i)), right(compute(i, last));
                    for (auto &&a : left)
                        for (auto &&b : right) {
                            switch (operators[i]) {
                                case '+': ret.push_back(a + b); break;
                                case '-': ret.push_back(a - b); break;
                                case '*': ret.push_back(a * b); break;
                                default: break;
                            }
                        }
                }
                break;
            }
        }
        return ret;
    }

    vector<int> operands;
    vector<char> operators;
};

// Divide-and-conquer + memorization solution
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        istringstream in(input);
        int operand;
        char op;
        operators.push_back(0);
        while (in >> operand) {
            operands.push_back(operand);
            in >> op;
            operators.push_back(op);
        }
        ret.resize(operands.size() + 1, vector<vector<int> >(operands.size() + 1));
        compute(0, operands.size());
        return ret[0][operands.size()];
    }
    
private:
    void compute(int first, int last) {
        if (!ret[first][last].empty())
            return;
        switch (last - first) {
            case 0: ret[first][last].push_back(0); break;
            case 1: ret[first][last].push_back(operands[first]); break;
            default: {
                for (int i(first + 1); i < last; ++i) {
                    compute(first, i);
                    compute(i, last);
                    for (auto &&a : ret[first][i])
                        for (auto &&b : ret[i][last]) {
                            switch (operators[i]) {
                                case '+': ret[first][last].push_back(a + b); break;
                                case '-': ret[first][last].push_back(a - b); break;
                                case '*': ret[first][last].push_back(a * b); break;
                                default: break;
                            }
                        }
                }
                break;
            }
        }
    }

    vector<vector<vector<int> > > ret;
    vector<int> operands;
    vector<char> operators;
};
