class Solution {
    vector<vector<pair<int,int>>> adj;
    int anc[100000][17];
    int dist2root[100000];
    int depth[100000];
    int root=0;
    int maxdepth=0;
    int ancestorbase2(int n,int k){
        if(anc[n][k]<0) anc[n][k]=ancestorbase2(ancestorbase2(n,k-1),k-1);
        return anc[n][k]; ancestorbase2(ancestorbase2(n,k-1),k-1);
    }
    int kancestor(int n,int k){
        for(int i=0;(1<<i)<=k;i++){
            if(k&(1<<i)) n=ancestorbase2(n,i);
        }
        return n;
    }
    void dfs(int n,int prev,int d,int dist){
        anc[n][0]=prev;
        depth[n]=d;
        dist2root[n]=dist;
        maxdepth=max(maxdepth,d);
        for(auto [i,w]:adj[n]){
            if(i==prev) continue;
            dfs(i,n,d+1,dist+w);
        }
    }
    int lca(int a,int b){
        if(depth[a]>depth[b]) return lca(b,a);
        b=kancestor(b,depth[b]-depth[a]);
        
        if(a==b) return a;
        
        for(int i=logb(maxdepth)+1;i>=0;i--){
            if(ancestorbase2(a,i)==ancestorbase2(b,i)) continue;
            a=ancestorbase2(a,i);
            b=ancestorbase2(b,i);
        }

        return ancestorbase2(a,0);
    }
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        memset(anc,-1,sizeof(anc));
        int n=edges.size()+1;
        
        adj.resize(n);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        dfs(root,root,0,0);

        vector<int> res;
        for(auto q:queries){
            // sort(q.begin(),q.end(),[this](int a,int b){
            //     return depth[a]>depth[b];
            // });
            int a=q[0],b=q[1],c=q[2],t=lca(a,b);
            // cout<<t<<" "<<lca(t,c)<<endl;
            int d=dist2root[a]+dist2root[b]+dist2root[c]-dist2root[lca(a,b)]-dist2root[lca(b,c)]-dist2root[lca(c,a)];
            // d+=dist2root[t]+dist2root[c]-2*dist2root[lca(t,c)];
            res.push_back(d);
        }
        return res;
    }
};