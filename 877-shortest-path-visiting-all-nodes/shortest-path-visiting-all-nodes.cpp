class Solution {
    int n;
    int comp(int msk){
        return ((1<<n)-1)^msk;
    }
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        n=adj.size();
        set<tuple<int,int,int>> set;
        for(int i=0;i<n;i++) set.insert({0,i,comp(1<<i)});
        while(set.size()){
            auto [cst,cur,msk]=*set.begin();
            set.erase(*set.begin());
            if(msk==0) return cst;
            for(int i:adj[cur]){
                set.insert({cst+1,i,comp(comp(msk)|(1<<i))});
            }
        }
        return 0;
    }
};