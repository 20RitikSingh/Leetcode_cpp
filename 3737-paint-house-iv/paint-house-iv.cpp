class Solution {
    vector<vector<vector<long long>>> dp;
    long long rec(int n,vector<vector<int>>& cost,int idx,int prev,int opp){
        if(idx>=n/2) return 0;
        if(dp[idx][prev][opp]>0) return dp[idx][prev][opp];
        vector<bool> v(4,0),u(4,0);
        v[prev]=1;u[opp]=1;
        long long res=1e18;
        for(int i=0;i<3;i++){
            if(v[i]) continue;
            for(int j=0;j<3;j++){
                if(u[j] || i==j) continue;
                long long x=rec(n,cost,idx+1,i,j);
                res=min(res,x+cost[idx][i]+cost[n-1-idx][j]);
            }
        }
        dp[idx][prev][opp]=res;
        return res;
    }
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        dp=vector<vector<vector<long long>>>(n,vector<vector<long long>>(4,vector<long long>(4,0)));
        return rec(n,cost,0,3,3);
    }
};

// (23)12(13)