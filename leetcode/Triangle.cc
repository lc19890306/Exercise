// Top-down DP solution - O(n^2) time and space complexity
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.front().empty())
            return 0;
        int smallest(INT_MAX);
        for (int i(1); i < triangle.size(); ++i)
            for (int j(0); j < triangle[i].size(); ++j) {
                if (!j)
                    triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                if (i == triangle.size() - 1)
                    smallest = min(smallest, triangle[i][j]);
            }
        return triangle.size() == 1 ? triangle[0][0] : smallest;
    }
};

// Bottom-up DP solution - O(n^2) time and space complexity
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.front().empty())
            return 0;
        for (int i(triangle.size() - 2); i > -1; --i)
            for (int j(0); j < triangle[i].size(); ++j)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};

// Bottom-up DP solution - O(n^2) time complexity and O(n) space complexity
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.front().empty())
            return 0;
        vector<int> ret(triangle.back());
        for (int i(triangle.size() - 2); i > -1; --i)
            for (int j(0); j < triangle[i].size(); ++j)
                ret[j] = min(ret[j], ret[j + 1]) + triangle[i][j];
        return ret.front();
    }
};
