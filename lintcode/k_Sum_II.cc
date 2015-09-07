class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        if (k == 1) {
            vector<vector<int> > ret;
            if (find(A.begin(), A.end(), target) != A.end())
                ret.push_back({target});
            return ret;
        }
        sort(A.begin(), A.end());
        return kSum(A.begin(), A.end(), k, target);
    }
    
private:

    typedef vector<int>::iterator Iterator;

    vector<vector<int> > kSum(Iterator first, Iterator last, int k, int target) {
        vector<vector<int> > ret;
        if (k == 2) {
            auto left(first), right(last - 1);
            while (left < right) {
                auto sum(*left + *right);
                if (sum < target)
                    ++left;
                else if (target < sum)
                    --right;
                else {
                    ret.push_back({*left, *right});
                    ++left;
                    --right;
                }
            }
        }
        else {
            for (auto it(last - 1); it > first + k - 2; --it) {
                auto temp(kSum(first, it, k - 1, target - *it));
                for (auto &&vec : temp) {
                    vec.push_back(*it);
                    ret.push_back(vec);
                }
            }
        }
        return ret;
    }
};
