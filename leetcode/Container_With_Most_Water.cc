class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area(0);
        int left(0), right(height.size() - 1);
        while (left < right) {
            auto left_height(height[left]);
            auto right_height(height[right]);
            max_area = max(max_area, (right - left) * min(left_height, right_height));
            if (left_height < right_height) {
                do {
                    ++left;
                } while (left < right && height[left] <= left_height);
            }
            else {
                do {
                    --right;
                } while (left < right && height[right] <= right_height);
            }
        }
        return max_area;
    }
};
