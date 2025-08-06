

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        function<void(int, int, string)> dfs = [&](int left, int right, string current) {
            if (left == 0 && right == 0) {
                result.push_back(current);
                return;
            }
            if (left > 0) dfs(left - 1, right, current + "(");
            if (right > left) dfs(left, right - 1, current + ")");
        };
        dfs(n, n, "");
        return result;
    }
};
