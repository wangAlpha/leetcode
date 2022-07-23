class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for (int i = 1; i < numRows; ++i) {
            const auto& last = ans.back();
            auto cur = last;
            cur.push_back(1);
            for (int j = 2; j <= i; ++j) {
                cur[j - 1] = last[j - 2] + last[j - 1];
            }
            ans.emplace_back(cur);
        }
        return ans;
    }
};