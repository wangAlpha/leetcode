class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for (int i = 2; i <= n; ++i) {
            string curr;
            size_t start = 0, pos = 0;
            prev.push_back('#');
            while (pos < prev.size() && prev[pos] != '#') {
                while (prev[pos] == prev[start]) {
                    ++pos;
                }
                curr += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = curr;
        }
        return prev;
    }
};