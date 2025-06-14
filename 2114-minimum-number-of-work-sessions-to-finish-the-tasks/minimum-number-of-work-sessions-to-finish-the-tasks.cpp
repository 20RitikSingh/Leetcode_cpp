class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        sort(tasks.rbegin(), tasks.rend());           // 5⃣
        int FULL = (1 << n) - 1;

        /* 2⃣ pre‑compute subset sums */
        vector<int> sum(1 << n, 0);
        for (int m = 1; m <= FULL; ++m) {
            int lsb = m & -m;
            int idx = __builtin_ctz(lsb);
            sum[m] = sum[m ^ lsb] + tasks[idx];
        }

        /* 3⃣ bottom‑up bitmask DP */
        vector<uint8_t> dp(1 << n, n);                // 0..14 fits in a byte
        dp[0] = 0;
        for (int m = 1; m <= FULL; ++m) {
            for (int sub = m; sub; sub = (sub - 1) & m)
                if (sum[sub] <= sessionTime)
                    dp[m] = min<uint8_t>(dp[m], dp[m ^ sub] + 1);
        }
        return dp[FULL];
    }
};
