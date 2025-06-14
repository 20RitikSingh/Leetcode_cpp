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
    int help(vector<int> &s,vector<int> &vals){
        vector<int> v;
        for(int i:s) v.push_back(vals[i]);
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        memset(dp,-1,sizeof(dp));
        return rec(v,0,0);
    }
    void dfs(vector<vector<int>>& v,vector<vector<int>> &adj,int cur){
        v[cur].push_back(cur);
        for(int i:adj[cur]){
            dfs(v,adj,i);
            for(int j:v[i]) v[cur].push_back(j);
        }
    }
public:
    int goodSubtreeSum(vector<int>& vals, vector<int>& par) {
        int n=vals.size();
        vector<vector<int>> v(n);
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
        }
        dfs(v,adj,0);
        long long res=0;
        for(int i=0;i<n;i++){
            res+=help(v[i],vals);
            res%=mod;
        }
        return res;
    }
};