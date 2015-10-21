class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        nextPermutation(nums.begin(), nums.end());
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
