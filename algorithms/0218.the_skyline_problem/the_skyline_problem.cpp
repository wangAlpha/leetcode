class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> heights;
        for (const auto& b: buildings) {
            heights.push_back({b[0], -b[2]});
            heights.push_back({b[1], b[2]});
        }
        sort(heights.begin(), heights.end());

        multiset<int> cur_heights;
        cur_heights.insert(0);
        int last_max_height = 0;
        for (auto &h: heights) {
            if (h.second < 0) {
                cur_heights.insert(-h.second);
            } else {
                cur_heights.erase(cur_heights.find(h.second));
            }

            const int cur_max_height = *cur_heights.rbegin();
            if (cur_max_height != last_max_height) {
                ans.push_back({h.first, cur_max_height});
                last_max_height = cur_max_height;
            }
        }
        return ans;
    }
};