class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;
        for (const int& n: nums) {
            numbers.emplace_back(to_string(n));
        }
        sort(numbers.begin(), numbers.end(), [](auto& a, auto& b) {
            return b + a < a + b;
        });
        string ans;
        for (auto &n: numbers) {
            ans.append(n);
        }
        return ans[0] == '0' ? "0" : ans;
    }
};