int dp[300][301][601];

class Solution {
    vector<vector<pair<int, int>>> adj;

    int rec(int cur, int k, int t) {
        if (k == 0) return 0;
        int &res = dp[cur][k][t];
        if (res != -1) return res;
        res = -1e9;
        for (const auto &edge : adj[cur]) {
            int next = edge.first;
            int weight = edge.second;
            if (t > weight) {
                res = max(res, rec(next, k - 1, t - weight) + weight);
            }
        }
        return res;
    }

public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        // Faster initialization than memset
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= k; ++j)
                for (int l = 0; l <= t; ++l)
                    dp[i][j][l] = -1;

        adj.assign(n, {});  // reuse existing memory
        for (const auto &e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
        }

        int res = -1e9;
        for (int i = 0; i < n; ++i) {
            res = max(res, rec(i, k, t));
        }

        return max(-1, res);
    }
};
