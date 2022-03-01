class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1, 0);
        for (int i = 1; i < edges.size(); ++i) {
            parent[i] = i;
        }
        for (const auto &edge: edges) {
            int node1 = find(parent, edge[0]);
            int node2 = find(parent, edge[1]);
            if (node1 == node2) {
                return edge;
            } else {
                parent[node1] = node2;
            }
        }
        return vector<int>{0, 0};
    }

    int find(const vector<int> &parent, int x) {
        while (x != parent[x]) {
           x = parent[x]; 
        }
        return parent[x];
    }
};