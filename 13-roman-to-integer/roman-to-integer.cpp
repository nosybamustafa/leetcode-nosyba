
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman{
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            int value = roman[s[i]];
            if (i + 1 < s.size() && value < roman[s[i + 1]]) {
                result -= value; // subtract if smaller before bigger
            } else {
                result += value;
            }
        }
        return result;
    }
};
