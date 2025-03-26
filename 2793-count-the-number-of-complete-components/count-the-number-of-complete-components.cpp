class Solution {
    int dfs(vector<vector<int>> &adj,vector<bool> &v,vector<int> &parent, int curr,int &c,int p){
        parent[curr]=p;
        v[curr]=1;
        c++;
        for(auto i:adj[curr]) if(!v[i]) dfs(adj,v,parent,i,c,p);
        return c;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> v(n);
        vector<int> parent(n),count(n);
        vector<vector<int>> adj(n);
        int c=0;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(v[i]) continue;
            int x=0;
            parent[i]=i;
            dfs(adj,v,parent,i,x,i);
            count[i]=x-1;
            c++;
        }
        for(int i=0;i<n;i++){
            if(v[parent[i]] && adj[i].size()<count[parent[i]]){
                c--;
                v[parent[i]]=0;
            }
        }
        return c;
    }
};