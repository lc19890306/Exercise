// Backtracking solution - exponential time complexity at worst
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combinationSum_helper(candidates, 0, target);
        return ret;
    }

private:
  // always starts from current candidate element in order to avoid duplicate results
    void combinationSum_helper(vector<int> &candidates, int begin, int target) {
        for (int i(begin); i < candidates.size(); ++i) {
            if (target < candidates[i])
                return;
            else if (target > candidates[i]) {
                vec.push_back(candidates[i]);
                combinationSum_helper(candidates, i, target - candidates[i]);
                vec.pop_back();
            }
            else {
                vec.push_back(candidates[i]);
                ret.push_back(vec);
                vec.pop_back();
            }
        }
    }
    
    vector<int> vec;
    vector<vector<int> > ret;
};
