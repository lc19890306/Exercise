// O(n) time and O(1) space complexity
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int left(0), right(height.size() - 1), ret(0);
        while (left < right) {
            auto min(std::min(height[left], height[right]));
            if (min == height[left])
                while (++left < right && height[left] < min)
                    ret += min - height[left];
            else
                while (left < --right && height[right] < min)
                    ret += min - height[right];
        }
        return ret;
    }
};
