class Solution {
    int res=0;
    int dfs(vector<vector<int>> &adj,vector<int> &values,int k,int curr,int prev){
        long long sum=0;
        for(int i:adj[curr]){
            if(i==prev) continue;
            int x=dfs(adj,values,k,i,curr);
            if(x%k==0) res++;
            else sum+=x;
        }
        return (sum+values[curr])%k;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int x=dfs(adj,values,k,0,0);
        if(x%k==0) res++;
        return res;
    }
};