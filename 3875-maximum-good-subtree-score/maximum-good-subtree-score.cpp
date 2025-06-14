class Solution {
    static constexpr long long MOD = 1e9 + 7;

    // dp[idx][mask] – raw (un‑modded) best sum for suffix starting at idx
    long long dp[512][1 << 11];

    long long rec(const vector<int>& a, int idx, int mask) {
        if (idx == (int)a.size()) return 0;
        long long& memo = dp[idx][mask];
        if (memo != -1) return memo;

        // Option 1: skip this number
        long long best = rec(a, idx + 1, mask);

        // Option 2: take it if its digits do not conflict
        int m = mask;
        bool ok = true;
        int x = a[idx];
        while (x) {
            int d = x % 10;
            if (m & (1 << d)) { ok = false; break; }
            m |= 1 << d;
            x /= 10;
        }
        if (ok)
            best = max(best, rec(a, idx + 1, m) + a[idx]);

        return memo = best;
    }

    long long solveSubtree(int u,
                           vector<vector<int>>& children,
                           const vector<int>& vals,
                           vector<vector<int>>& bucket) {
        bucket[u].push_back(vals[u]);

        long long ans = 0;
        for (int v : children[u]) {
            ans = (ans + solveSubtree(v, children, vals, bucket)) % MOD;
            bucket[u].insert(bucket[u].end(), bucket[v].begin(), bucket[v].end());
        }

        /* local DP: only need |bucket[u]| rows  */
        int sz = (int)bucket[u].size();
        for (int i = 0; i < sz; ++i)
            std::fill(dp[i], dp[i] + (1 << 11), -1);

        long long rawBest = rec(bucket[u], 0, 0);
        ans = (ans + rawBest % MOD) % MOD;
        return ans;
    }

public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& parent) {
        int n = (int)vals.size();
        vector<vector<int>> children(n), bucket(n);
        for (int i = 1; i < n; ++i)
            children[parent[i]].push_back(i);

        return (int)solveSubtree(0, children, vals, bucket);
    }
};
