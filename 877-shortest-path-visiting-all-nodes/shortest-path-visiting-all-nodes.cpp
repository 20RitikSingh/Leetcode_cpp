class Solution {
    int n;
    int comp(int msk){
        return ((1<<n)-1)^msk;
    }
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        n=adj.size();
        set<tuple<int,int,int>> set;
        for(int i=0;i<n;i++) set.insert({0,comp(1<<i),i});
        while(set.size()){
            auto [cst,msk,cur]=*set.begin();
            set.erase(*set.begin());
            if(msk==0) return cst;
            for(int i:adj[cur]){
                set.insert({cst+1,comp(comp(msk)|(1<<i)),i});
            }
        }
        return 0;
    }
};