struct DSU{
    vector<int> parent,rank,maxele,count,val;
    DSU(int n,vector<int> &vals){
        parent.resize(n);
        rank.resize(n,1);
        count.resize(n,1);
        maxele.resize(n);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<n;i++) maxele[i]=vals[i];
    }
    int add(int x,int y){
        int res=0;
        x=anc(x),y=anc(y);
        if(x==y) return 0;
        if(rank[x]<rank[y]) swap(x,y);

        // cout<<x<<" "<<y<<endl;
        // cout<<maxele[x]<<" "<<maxele[y]<<endl;
        // cout<<count[x]<<" "<<count[y]<<endl;
        int mx=max(maxele[x],maxele[y]);
        if(maxele[x]==maxele[y]) res+=count[x]*count[y];
        if(maxele[x]!=mx) count[x]=0;
        if(maxele[y]==mx) count[x]+=count[y];
        maxele[x]=mx;
        // cout<<maxele[x]<<endl;
        // cout<<endl;

        rank[x]+=rank[y];
        parent[y]=x;
        return res;
    }
    int anc(int x){
        if(parent[x]!=x) parent[x]=anc(parent[x]);
        return parent[x];
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        sort(edges.begin(),edges.end(),[&](auto a, auto b){
            return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
        });
        int res=0;
        DSU dsu(n,vals);
        for(auto e:edges){
            res+=dsu.add(e[0],e[1]);
        }
        return res+n;
    }
};