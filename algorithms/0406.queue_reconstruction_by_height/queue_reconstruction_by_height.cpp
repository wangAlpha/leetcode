class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const auto &a, const auto &b) {
            if (a[0] == b[0]) { return a[1] < b[1]; }
            return a[0] > b[0];
        };
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> queue;
        for (const auto &p: people) {
            int position = p[1];
            auto it = queue.begin();
            while (position--) {
                ++it;
            }
            queue.insert(it, p);
        }
        return vector<vector<int>>(queue.begin(), queue.end());
    }
};