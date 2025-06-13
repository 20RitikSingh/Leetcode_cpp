int dp[300][301][601];
class Solution {
    vector<vector<pair<int,int>>> adj;
    int rec(int cur,int k,int t){
        if(k==0) return 0;
        int res=-1e9;
        if(dp[cur][k][t]!=-1) return dp[cur][k][t];
        for(auto [i,w]:adj[cur]){
            if(t>w) res=max(res,rec(i,k-1,t-w)+w);
        }
        dp[cur][k][t]=res;
        return res;
    }
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= k; ++j)
                for (int l = 0; l <= t; ++l)
                    dp[i][j][l] = -1;

        adj.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        int res=-1e9;
        for(int i=0;i<n;i++){
            res=max(res,rec(i,k,t));
        }
        return max(-1,res);
    }
};