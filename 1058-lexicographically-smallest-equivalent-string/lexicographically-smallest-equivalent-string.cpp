class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    void add(int x,int y){
        x=anc(x),y=anc(y);
        if(x==y) return;
        if(x>y)  swap(y,x);
        parent[y]=x;
    }
    int anc(int x){
        if(parent[x]==x) return x;
        parent[x]=anc(parent[x]);
        return parent[x]; 
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DSU dsu('z'+1);
        for(int i=0;i<s1.size();i++) dsu.add(s1[i],s2[i]);
        for(auto &ch:baseStr) ch=dsu.anc(ch);
        return baseStr;
    }
};