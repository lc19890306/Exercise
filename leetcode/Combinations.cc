// Backtracking solution - O(n^k) time complexity
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        combine(n, 1, k);
        return ret;
    }
    
private:
    void combine(int n, int begin, int k) {
        if (!k) {
            ret.push_back(vec);
            return;
        }
        for (int i(begin); i <= n; ++i) {
            vec.push_back(i);
            combine(n, i + 1, k - 1);
            vec.pop_back();
        }
    }
    
    vector<int> vec;
    vector<vector<int> > ret;
};
