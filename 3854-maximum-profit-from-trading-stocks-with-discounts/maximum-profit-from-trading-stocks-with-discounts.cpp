#include <vector>
#include <algorithm>
using namespace std;

const int NINF = -10000000;

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> children(n+1);
        for (auto& edge : hierarchy) {
            int u = edge[0], v = edge[1];
            children[u].push_back(v);
        }

        function<pair<vector<int>, vector<int>>(int)> dfs = [&](int u) {
            vector<int> g0(budget+1, NINF);
            vector<int> g1(budget+1, NINF);
            g0[0] = 0;
            g1[0] = 0;

            for (int v : children[u]) {
                auto [res0_v, res1_v] = dfs(v);

                vector<int> new_g0(budget+1, NINF);
                for (int b1 = 0; b1 <= budget; ++b1) {
                    if (g0[b1] == NINF) continue;
                    for (int b2 = 0; b2 <= budget - b1; ++b2) {
                        if (res0_v[b2] == NINF) continue;
                        int total_b = b1 + b2;
                        if (total_b > budget) continue;
                        if (g0[b1] + res0_v[b2] > new_g0[total_b]) {
                            new_g0[total_b] = g0[b1] + res0_v[b2];
                        }
                    }
                }
                g0 = move(new_g0);

                vector<int> new_g1(budget+1, NINF);
                for (int b1 = 0; b1 <= budget; ++b1) {
                    if (g1[b1] == NINF) continue;
                    for (int b2 = 0; b2 <= budget - b1; ++b2) {
                        if (res1_v[b2] == NINF) continue;
                        int total_b = b1 + b2;
                        if (total_b > budget) continue;
                        if (g1[b1] + res1_v[b2] > new_g1[total_b]) {
                            new_g1[total_b] = g1[b1] + res1_v[b2];
                        }
                    }
                }
                g1 = move(new_g1);
            }

            vector<int> res0(budget+1, NINF);
            vector<int> res1(budget+1, NINF);
            int idx = u - 1;
            int cost0 = present[idx];
            int cost1 = present[idx] / 2;

            for (int b = 0; b <= budget; ++b) {
                res0[b] = g0[b];
                res1[b] = g0[b];

                if (b >= cost0) {
                    int rem = b - cost0;
                    if (rem >= 0 && g1[rem] != NINF) {
                        int profit = future[idx] - cost0;
                        if (res0[b] < profit + g1[rem]) {
                            res0[b] = profit + g1[rem];
                        }
                    }
                }

                if (b >= cost1) {
                    int rem = b - cost1;
                    if (rem >= 0 && g1[rem] != NINF) {
                        int profit = future[idx] - cost1;
                        if (res1[b] < profit + g1[rem]) {
                            res1[b] = profit + g1[rem];
                        }
                    }
                }
            }

            return make_pair(res0, res1);
        };

        auto [res0_root, res1_root] = dfs(1);
        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            if (res0_root[b] > ans) {
                ans = res0_root[b];
            }
        }
        return ans;
    }
};