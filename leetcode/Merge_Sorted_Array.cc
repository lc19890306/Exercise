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

// Best for this problem
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1(m - 1), i2(n - 1), j(m + n - 1);
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] < nums2[i2])
                nums1[j--] = nums2[i2--];
            else
                nums1[j--] = nums1[i1--];
        }
        while (i2 >= 0)
            nums1[j--] = nums2[i2--];
    }
};
