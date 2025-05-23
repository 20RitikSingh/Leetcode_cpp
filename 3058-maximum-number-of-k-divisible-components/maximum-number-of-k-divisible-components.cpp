class Solution {
    int res=0;
    // int dp[30000][30000];
    
    int dfs(vector<vector<int>> &adj,vector<int> &values,int k,int curr,int prev){
        long long sum=0;
        // if(dp[curr][prev]!=-1) return dp[curr][prev];
        for(int i:adj[curr]){
            if(i==prev) continue;
            int x=dfs(adj,values,k,i,curr);
            if(x%k==0) res++;
            else sum+=x;
        }
        // dp[curr][prev]=sum+values[curr];
        return (sum+values[curr])%k;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // memset(dp,-1,sizeof(dp));

        int ans=0;
        for(int i=0;i<1;i++){
            res=0;
            int x=dfs(adj,values,k,i,i);
            if(x%k==0) res++;
            ans=max(ans,res);
        }
        return ans;
    }
};