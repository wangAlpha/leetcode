class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        const int len = citations.size();
        int h = 0;
        for (int i = 0; i < len; ++i) {
            int n = len - i;
            if (n <= citations[i]) {
                return n;
            }
        }
        return 0;
    }
};