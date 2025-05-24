class Solution {
   
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> adj(n),v(n,vector<int>(26));
        vector<int> ind(n);
        queue<int> q;
        int p=0,last=0,res=1;
        for(auto e:edges){
            ind[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            colors[i]-='a';
            v[i][colors[i]]++;
            if(!ind[i]) q.push(i);
        }
        while(q.size()){
            int cur=q.front();
            last=cur;
            p++;
            q.pop();
            for(int i:adj[cur]){
                ind[i]--;
                if(!ind[i]) q.push(i);
                for(int j=0;j<26;j++){
                    v[i][j]=max(v[i][j],v[cur][j]+(j==colors[i]));
                    res=max(res,v[i][j]);
                }
            }
        }
        if(p!=n) return -1;
        return res;
    }
};