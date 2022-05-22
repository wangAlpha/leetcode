class Solution {
public:
    vector<string> findItinerary(const vector<vector<string>>& tickets) {
        vector<string> ans;
        if (tickets.empty()) {
            return ans;
        }
        unordered_map<string, multiset<string>> hash;
        for (auto& ticket : tickets) {
            hash[ticket[0]].emplace(ticket[1]);
        }
        stack<string> s;
        s.emplace("JFK");
        while (!s.empty()) {
            auto& cur = s.top();
            if (hash[cur].empty()) {
                ans.emplace_back(cur);
                s.pop();
            } else {
                auto value = hash[cur].begin();
                s.emplace(*value);
                hash[cur].erase(value);
            }
        }
        reverse(ans.begin(), ans.end());
        return move(ans);
    }
};