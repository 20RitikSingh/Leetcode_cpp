class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> ind(n);
        queue<int> q;
        for(auto &e:edges){
            ind[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        int p=0;
        for(int i=0;i<n;i++) if(!ind[i]) q.push(i),p++;
        while(p<n && q.size()){
            for(int i:adj[q.front()]){
                ind[i]--;
                if(ind[i]==0) q.push(i),p++;
            }
            q.pop();
        }
        return p==n;
    }
};