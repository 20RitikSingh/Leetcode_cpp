class Solution {
    int dfs(vector<unordered_set<int>> &adj,vector<bool> &v,vector<bool> &vis, int curr){
        vis[curr]=1;
        v[curr]=1;
        bool x=1;
        for(int i=0;i<vis.size();i++) if(curr!=i && vis[i] && adj[curr].count(i)==0){ x=0; break;}
        for(auto i:adj[curr]) if(!v[i]) x&=dfs(adj,v,vis,i);
        return x;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> v(n);
        vector<unordered_set<int>> adj(n);
        int c=0;
        for(auto e:edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        for(int i=0;i<n;i++){
            if(v[i]) continue;
            vector<bool> vis(n);
            c+=dfs(adj,v,vis,i);
        }
        return c;
    }
};