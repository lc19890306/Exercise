// DP solution - O(m*n) time and space complexity
// 0 1 1 1 0 1 0     0 1 1 1 0 1 0 : 3
// 1 0 1 1 0 1 0 ==> 1 0 2 2 0 2 0 : 4
// 1 1 1 1 1 0 1     2 1 3 3 1 0 1 : 6 <== max
// 0 0 0 1 1 1 1     0 0 0 4 2 1 2 : 4
// for each row, if not 0, add the previous row, otherwise, set 0
// calculate the largest rectangle area of the entire row
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;
        int max_area(0);
        vector<vector<int> > heights(matrix.size() + 1, vector<int>(matrix.front().size()));
        for (int row(1); row < heights.size(); ++row) {
            for (int col(0); col < heights[row].size(); ++col) {
                heights[row][col] = matrix[row - 1][col] == '0' ? 0 : heights[row - 1][col] + 1;
            }
            auto area(largestRectangleArea(heights[row]));
            max_area = max(max_area, area);
        }
        return max_area;
    }
    
private:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int max_area(0);
        stack<int> s;
        for (int i(0); i < height.size(); ++i) {
            while (!s.empty() && height[i] < height[s.top()]) {
                auto top(s.top());
                s.pop();
                auto area(height[top] * (i - (s.empty() ? 0 : s.top() + 1)));
                max_area = max(max_area, area);
            }
            s.push(i);
        }
        return max_area;
    }
};

// Optimized DP solution - O(m*n) time and O(n) space complexity
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;
        int max_area(0);
        vector<int> height(matrix.front().size());
        for (int row(0); row < matrix.size(); ++row) {
            for (int col(0); col < matrix[row].size(); ++col) {
                height[col] = matrix[row][col] == '0' ? 0 : height[col] + 1;
            }
            auto area(largestRectangleArea(height));
            max_area = max(max_area, area);
        }
        return max_area;
    }
    
private:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int max_area(0);
        stack<int> s;
        for (int i(0); i < height.size(); ++i) {
            while (!s.empty() && height[i] < height[s.top()]) {
                auto top(s.top());
                s.pop();
                auto area(height[top] * (i - (s.empty() ? 0 : s.top() + 1)));
                max_area = max(max_area, area);
            }
            s.push(i);
        }
        return max_area;
    }
};

// DP solution - O(m*n) time and O(n) space complexity - BEST for this problem!!!
// https://leetcode.com/discuss/20240/share-my-dp-solution
// http://liangjiabin.com/blog/2015/04/leetcode-maximal-rectangle.html
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;
        int max_area(0), m(matrix.size()), n(matrix.front().size());
        vector<int> height(n), left(n), right(n, n);
        for (int row(0); row < matrix.size(); ++row) {
            // height
            for (int col(0); col < matrix[row].size(); ++col)
                height[col] = matrix[row][col] == '1' ? height[col] + 1 : 0;
            // left[j] is the leftest position where continuous 1 begins
            int cur_left(0);
            for (int col(0); col < matrix[row].size(); ++col) {
                if (matrix[row][col] == '1')
                    left[col] = max(left[col], cur_left);
                else {
                    left[col] = 0;
                    cur_left = col + 1;
                }
            }
            // right[j] is the rightest position where continuous 1 ends
            int cur_right(n);
            for (int col(n - 1); col >= 0; --col) {
                if (matrix[row][col] == '1')
                    right[col] = min(right[col], cur_right);
                else {
                    right[col] = n;
                    cur_right = col;
                }
            }
            // compute area
            for (int col(0); col < matrix[row].size(); ++col) {
                auto area((right[col] - left[col]) * height[col]);
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};
