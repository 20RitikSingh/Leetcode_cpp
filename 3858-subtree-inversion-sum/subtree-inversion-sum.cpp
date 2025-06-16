class Solution {
    using ll = long long;
    const ll INF = 1e15; // use original sentinel for minimal change

    vector<vector<int>> adj;
    vector<int> values;
    int maxCooldown;
    vector<vector<pair<ll, ll>>> dp;

    pair<ll, ll> dfs(int node, int parent, int k) {
        if (dp[node][k].first != INF) return dp[node][k];

        ll mi = values[node], mx = values[node], mi1 = values[node], mx1 = values[node];

        for (int child : adj[node]) {
            if (child == parent) continue;

            auto [x, y] = dfs(child, node, max(0, k - 1));
            mi += x;
            mx += y;

            if (k <= 0) {
                auto [p, q] = dfs(child, node, maxCooldown);
                mi1 += p;
                mx1 += q;
            }
        }

        if (k <= 0) {
            dp[node][k] = {min(mi, -mx1), max(mx, -mi1)};
        } else {
            dp[node][k] = {mi, mx};
        }

        return dp[node][k];
    }

public:
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        int n = nums.size();
        adj.assign(n, {});
        values = nums;
        maxCooldown = k - 1;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dp.assign(n, vector<pair<ll, ll>>(k + 1, {INF, -INF}));

        return dfs(0, -1, 0).second;
    }
};