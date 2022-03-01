class Solution {
public:
    int countBinarySubstrings(string &s) {
        int ans = 0;
        int pre_cnt = 0;
        int cur_cnt = 0;
        char last = '-';
        s += last;
        for (const char &c: s) {
            if (c != last) {
                last = c;
                ans += min(cur_cnt, pre_cnt);
                pre_cnt = cur_cnt;
                cur_cnt = 0;
            }
            cur_cnt += 1;
        }
        return ans;
    }
};