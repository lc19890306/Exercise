// O(n) time and space complexity
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        stack<int> s;
        int max_area(0);
        for (int i(0); i < height.size(); ++i) {
            while (!s.empty() && height[i] < height[s.top()]) {
                auto top(s.top());
		// each time pop an element, calculate the area
		// if stack is empty, area = height of element just poped * i
		// otherwise, area = height of element just poped * (current top of stack + 1)
                s.pop();
                auto area(height[top] * (i - (s.empty() ? 0 : s.top() + 1)));
                max_area = max(max_area, area);
            }
            s.push(i);
        }
        return max_area;
    }
};
