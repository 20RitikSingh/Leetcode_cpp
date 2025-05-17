vector<vector<int>> adj = {{4, 6}, {8, 6},    {7, 9}, {4, 8}, {0, 3, 9},
                           {},     {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
int mod = 1e9 + 7;
vector<vector<int>> matMul(vector<vector<int>>& x, vector<vector<int>>& y) {
    int mx = x.size(), nx = x[0].size(), my = y.size(), ny = y[0].size();
    if (nx != my)
        return {{}};
    vector<vector<int>> res(mx, vector<int>(ny));
    for (int i = 0; i < mx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nx; k++) {
                res[i][j] = (res[i][j] + 1LL * x[i][k] * y[k][j]) % mod;
            }
        }
    }
    return res;
}
vector<vector<int>> matPow(vector<vector<int>>& x, int p) {
    if (x.size() != x[0].size())
        return {{}};
    if (p == 1)
        return x;
    vector<vector<int>> tmp = matPow(x, p / 2);
    tmp = matMul(tmp, tmp);
    if (p % 2)
        tmp = matMul(tmp, x);
    return tmp;
}
class Solution {
public:
    int knightDialer(int n) {
        if (n < 2)
            return 10;
        long long res = 0;
        vector<vector<int>> mat(10, vector<int>(10)), dp(1, vector<int>(10, 1)),
            tmp(10, vector<int>(1, 1));
        for (int i = 0; i < 10; i++)
            for (int j : adj[i])
                mat[i][j] = 1;
        mat = matPow(mat, n - 1);
        dp = matMul(dp, mat);
        tmp = matMul(dp, tmp);
        return tmp[0][0];
    }
};