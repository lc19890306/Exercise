class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        do {ret.push_back(nums);} while (next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        do {ret.push_back(nums);} while (nextPermutation(nums.begin(), nums.end()));
        return ret;
    }
    
private:
    typedef vector<int>::iterator Iterator;
    
    bool nextPermutation(Iterator first, Iterator last) {
        if (first == last)
            return false;
        auto i(last);
        if (first == --i)
            return false;
        while (true) {
            auto i1(i);
            if (*--i < *i1) {
                auto i2(last);
                while (!(*i < *--i2))
                    ;
                swap(*i, *i2);
                reverse(i1, last);
                return true;
            }
            if (i == first) {
                reverse(first, last);
                return false;
            }
        }
    }
};
