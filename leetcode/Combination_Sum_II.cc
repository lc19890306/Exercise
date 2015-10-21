// Backtracking solution
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, 0, target);
        return ret;
    }
    
private:
    void combinationSum2(vector<int> &candidates, int begin, int target) {
        for (int i(begin); i < candidates.size(); ++i) {
	  // Compared with combination_sum, candidates may contain duplicated elements, so skip them in order to avoid duplicated recursions
            if (i != begin && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i])
                return;
            else if (target > candidates[i]) {
                vec.push_back(candidates[i]);
                combinationSum2(candidates, i + 1, target - candidates[i]);
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
