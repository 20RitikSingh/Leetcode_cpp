class Solution {
    using ll = long long;
    const ll INF = 4e18;

    vector<vector<int>> adj;
    vector<int> values;
    int maxCooldown;
    vector<vector<pair<ll, ll>>> dp;

    pair<ll, ll> dfs(int node, int parent, int k) {
        if (dp[node][k].first != INF) return dp[node][k];

        ll sumMin = values[node], sumMax = values[node];
        ll altMin = values[node], altMax = values[node];

        bool canInvert = (k <= 0);

        for (int child : adj[node]) {
            if (child == parent) continue;

            auto [minSub, maxSub] = dfs(child, node, max(0, k - 1));
            sumMin += minSub;
            sumMax += maxSub;

            if (canInvert) {
                auto [invMinSub, invMaxSub] = dfs(child, node, maxCooldown);
                altMin += invMinSub;
                altMax += invMaxSub;
            }
        }

        if (canInvert) {
            dp[node][k] = {
                min(sumMin, -altMax),
                max(sumMax, -altMin)
            };
        } else {
            dp[node][k] = {sumMin, sumMax};
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
