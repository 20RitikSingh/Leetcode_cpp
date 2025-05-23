class Solution {
    int res = 0;

    int dfs(vector<vector<int>> &adj, vector<int> &values, int k, int curr, int parent) {
        long long sum = 0;
        for (int neighbor : adj[curr]) {
            if (neighbor == parent) continue;
            int sub = dfs(adj, values, k, neighbor, curr);
            if (sub % k == 0) res++;
            else sum += sub;
        }
        return (sum + values[curr]) % k;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        res = 0;
        int root_sum = dfs(adj, values, k, 0, -1);
        if (root_sum % k == 0) res++;
        return res;
    }
};
