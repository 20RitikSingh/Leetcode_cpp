class Solution {
    int mod=1e9+7;
    int dp[500][1<<11];
    long long rec(vector<int> &v,int idx,int msk){
        if(idx==v.size()) return 0;
        if(dp[idx][msk]!=-1) return dp[idx][msk];
        long long res=rec(v,idx+1,msk);
        bool f=1;
        int newmsk=msk,x=v[idx];

        while(x){
            if(newmsk&(1<<(x%10))){
                f=0;
                break;
            }
            newmsk|=1<<(x%10);
            x/=10;
        }

        if(f) res=max(res,(rec(v,idx+1,newmsk)+v[idx])%mod);
        dp[idx][msk]=res;
        return res;
    }
    int dfs(vector<vector<int>>& v,vector<vector<int>> &adj,int cur,vector<int> &vals){
        v[cur].push_back(vals[cur]);
        int res=0;
        for(int i:adj[cur]){
            res=(1LL*res+dfs(v,adj,i,vals))%mod;
            for(int j:v[i]) v[cur].push_back(j);
        }
        int sz =v[cur].size();
        for (int i = 0; i < sz; ++i)
            std::fill(dp[i], dp[i] + (1 << 11), -1);
        res=(1LL*res+rec(v[cur],0,0))%mod;
        return res;
    }
public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n=vals.size();
        vector<vector<int>> v(n);
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
        }
        return dfs(v,adj,0,vals);
    }
};