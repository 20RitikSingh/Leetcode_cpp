class Solution {
    vector<vector<int>> adj;
    vector<bool> localVis,globalVis;
    int rec(int cur){
        if(localVis[cur]) return -1;
        if(globalVis[cur]) return 0;
        globalVis[cur]=1;
        localVis[cur]=1;
        for(int i:adj[cur]){
            int x=rec(i);
            if(x<0) return -1;
        }
        localVis[cur]=0;
        return 0;       
    }
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        localVis.resize(n);
        globalVis.resize(n);
        for(auto e:edges){
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(globalVis[i]) continue;
            localVis=vector<bool>(n);
            if(rec(i)<0) return 0;
        }
        return 1;
    }
};