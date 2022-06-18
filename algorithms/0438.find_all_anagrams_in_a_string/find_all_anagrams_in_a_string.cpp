class Solution {
public:
    vector<int> findAnagrams(const string& s, const string& p) {
        vector<int> ans;
        deque<char> q;
        const int n = p.size();
        array<int, 26> sub_alpha = {0};
        array<int, 26> main_alpha = {0};
        for (const char &c: p) {
            ++sub_alpha[c - 'a'];
        }
        for (int i = 0; i < s.size(); ++i) {
            const char& c = s[i];
            const auto index = c - 'a';
            q.push_back(c);
            ++main_alpha[index];
            if (q.size() > n) {
                --main_alpha[q.front() - 'a'];
                q.pop_front();
            }
            if (sub_alpha[index] == main_alpha[index] && sub_alpha == main_alpha) {
                ans.push_back(i - n + 1);
            }
        }
        return ans;
    }
};