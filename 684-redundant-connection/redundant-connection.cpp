struct DSU{
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        iota(parent.begin(),parent.end(),0);
    }
    int add(int x,int y){
        x=anc(x),y=anc(y);
        if(x==y) return 0;
        if(rank[x]<rank[y]) swap(x,y);
        rank[x]+=rank[y];
        parent[y]=x;
        return 1;
    }
    int anc(int x){
        if(x!=parent[x]) parent[x]=anc(parent[x]);
        return parent[x];
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(auto e:edges) if(!dsu.add(e[0]-1,e[1]-1)) return e;
        return {};
    }
};