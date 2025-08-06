
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int maxArea = 0;
        heights.push_back(0);  // Add a zero height to flush out remaining bars in stack

        for (int i = 0; i < heights.size(); ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int h = heights[stk.top()];
                stk.pop();
                int w = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            stk.push(i);
        }

        return maxArea;
    }
};
