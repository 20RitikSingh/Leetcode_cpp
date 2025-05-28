class Solution {
    int bfs(vector<vector<int>> &adj,int cur,int k){
        if(cur<0) return 0;
        queue<int> q;
        int c=0;
        vector<int> vis(adj.size());
        q.push(cur);
        vis[cur]++;
        while(q.size() && k){
            int sz=q.size();
            while(sz--){
                cur=q.front();
                for(int i:adj[cur]) if(!vis[i]) q.push(i), vis[i]++;
                q.pop();
                c++;
            }
            k--;
        }
        return c;
    }
    void build(vector<vector<int>> &adj,vector<vector<int>> &edges){
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>> adj(m);
        build(adj,edges2);
        int span2=0;
        for(int i=0;i<m;i++){
            span2=max(span2,bfs(adj,i,k));
        }
        cout<<span2<<endl;
        adj=vector<vector<int>>(n);
        build(adj,edges1);
        vector<int> res(n);
        for(int i=0;i<n;i++){
            int x=bfs(adj,i,k+1);
            res[i]=x+span2;
        }
        return res;
    }
};