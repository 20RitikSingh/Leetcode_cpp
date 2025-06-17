class Solution {
    long long dp[100001][4][4];
    long long rec(vector<vector<int>> &cost,int idx,int l,int r){
        long long res=1e15,n=cost.size();
        if(idx==n/2) return 0;
        if(dp[idx][l][r]) return dp[idx][l][r]-1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==j || i==l || j==r) continue;
                res=min(res,rec(cost,idx+1,i,j)+cost[idx][i]+cost[n-1-idx][j]);
            }
        }
        dp[idx][l][r]=res+1;
        return res;
    }
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        return rec(cost,0,3,3);
    }
};