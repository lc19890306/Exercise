// Backtracking solution
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        combinationSum3(k, 1, n);
        return ret;
    }
    
private:
    void combinationSum3(int k, int begin, int n) {
        if (!k) {
            if (!n)
                ret.push_back(vec);
            return;
        }
        for (int i(begin); i < 10; ++i) {
            if (n < i)
                return;
            else {
                vec.push_back(i);
                combinationSum3(k - 1, i + 1, n - i);
                vec.pop_back();
            }
        }
    }
    
    vector<int> vec;
    vector<vector<int> > ret;
};
