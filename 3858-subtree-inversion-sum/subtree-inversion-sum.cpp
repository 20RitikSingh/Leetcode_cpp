class Solution {
    vector<vector<int>> adj;
    vector<int> v;
    int cooldown;
    pair<long long,long long> dp[100001][51];
    pair<long long,long long> dfs(int cur,int prev,int k){
        if(dp[cur][k]!=make_pair(1e15,-1e15)) return dp[cur][k];
        long long mi=v[cur],mx=v[cur],mi1=v[cur],mx1=v[cur];
        pair<long long ,long long> res={mi,mx};
        for(int i:adj[cur]){
            if(prev==i) continue;
            auto [x,y]=dfs(i,cur,max(0,k-1));
            mi+=x;
            mx+=y;
            if(k<=0) {
                auto [p,q]=dfs(i,cur,cooldown);
                mi1+=p;
                mx1+=q;
            }
        }
        if(k<=0){
            res.first=min(mi,-mx1);
            res.second=max(mx,-mi1);
        }else res={mi,mx};
        dp[cur][k]=res;
        return res;
    }
public:
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        int n=nums.size();
        adj.resize(n);
        v=nums;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        cooldown=k-1;
        for(int i=0;i<n;i++) for(int j=0;j<k+1;j++) dp[i][j]={1e15,-1e15};
        return dfs(0,-1,0).second;
    }
};