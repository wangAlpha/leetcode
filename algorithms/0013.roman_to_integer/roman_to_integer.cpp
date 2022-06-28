class Solution {
public:
    int romanToInt(const string& s) {
        int last = 0;
        int ans = 0;
        for (const char& c: s) {
            int cur = roman_map[c];
            if (cur > last) {
                ans -= (last << 1);
            }
            ans += cur;
            last = cur;
        }
        return ans;
    }
private:
    unordered_map<char, int> roman_map = {
        {'I',1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
};