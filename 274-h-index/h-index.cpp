

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h = 0;
        for (int i = 0; i < n; i++) {
            int papersWithAtLeastH = n - i;
            if (citations[i] >= papersWithAtLeastH) {
                h = papersWithAtLeastH;
                break;
            }
        }
        return h;
    }
};
