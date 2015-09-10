class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1.begin(), nums1.begin() + m);
        auto it(nums1.begin()), it1(temp.begin()), it2(nums2.begin());
        while (it1 != temp.end() && it2 != nums2.end())
            if (*it1 < *it2)
                *it++ = *it1++;
            else
                *it++ = *it2++;
        if (it1 == temp.end())
            copy(it2, nums2.end(), it);
        else
            copy(it1, temp.end(), it);
    }
};
