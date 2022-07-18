class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strings;
        for (int &n : nums) {
            strings.push_back(to_string(n));
        }
        sort(strings.begin(), strings.end(), [](auto &a, auto &b) {
            return a + b < b + a;
        });
        string str;
        for (auto &n : strings) {
            str.append(n);
        }
        return str;
    }
};