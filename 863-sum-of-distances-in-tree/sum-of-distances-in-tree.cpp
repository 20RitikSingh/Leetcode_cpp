class Solution {
    vector<int> res,v;
    vector<vector<int>> adj;
    int dfs(int cur,int prev,int d){
        int ans=1;
        res[0]+=d;
        for(int i:adj[cur]){
            if(i==prev) continue;
            v[i]=dfs(i,cur,d+1);
            ans+=v[i];
        }
        return ans;
    }
    void dfs1(int cur,int prev){
        int n=adj.size();
        for(int i:adj[cur]){
            if(i==prev) continue;
            res[i]=res[cur]+n-2*v[i];
            dfs1(i,cur);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        res.resize(n);
        v.resize(n);
        adj.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1,0);
        dfs1(0,-1);
        return res;
    }
};