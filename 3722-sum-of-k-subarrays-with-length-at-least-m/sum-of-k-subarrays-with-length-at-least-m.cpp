

class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        if (k * m > n) {
            return INT_MIN;
        }

        vector<long long> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, LLONG_MIN));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int j = 1; j <= k; j++) {
            long long best = LLONG_MIN;
            vector<long long> last(n + 1, LLONG_MIN);

            for (int i = 0; i <= n; i++) {
                if (i >= m) {
                    if (dp[i - m][j - 1] != LLONG_MIN) {
                        long long candidate_best = dp[i - m][j - 1] - pre[i - m];
                        if (candidate_best > best) {
                            best = candidate_best;
                        }
                    }
                }

                if (i >= 1) {
                    if (last[i - 1] != LLONG_MIN) {
                        last[i] = last[i - 1] + nums[i - 1];
                    }
                }

                if (i >= m && best != LLONG_MIN) {
                    long long candidate_new = pre[i] + best;
                    if (last[i] == LLONG_MIN || candidate_new > last[i]) {
                        last[i] = candidate_new;
                    }
                }

                if (i == 0) {
                    dp[i][j] = last[i];
                } else {
                    if (dp[i - 1][j] == LLONG_MIN) {
                        dp[i][j] = last[i];
                    } else if (last[i] == LLONG_MIN) {
                        dp[i][j] = dp[i - 1][j];
                    } else {
                        dp[i][j] = max(dp[i - 1][j], last[i]);
                    }
                }
            }
        }

        return (dp[n][k] == LLONG_MIN) ? INT_MIN : dp[n][k];
    }
};