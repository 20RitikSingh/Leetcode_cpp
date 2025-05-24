class Solution {
    vector<vector<int>> adj;
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        vector<int> ind(n);
        queue<int> q;
        for(auto e:edges){
            ind[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(!ind[i]) q.push(i);
        }
        int p=0;
        while(q.size()){
            int cur=q.front();
            p++;
            q.pop();
            for(int i:adj[cur]){
                ind[i]--;
                if(ind[i]==0) q.push(i);
            }
        }
        return p==n;
    }
};