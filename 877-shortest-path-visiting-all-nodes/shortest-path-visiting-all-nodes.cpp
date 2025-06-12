class Solution {
public:
    int shortestPathLength(vector<vector<int>>& adj) {
        int n=adj.size();
        set<tuple<int,int,int>> set;
        for(int i=0;i<n;i++) set.insert({0,i,1<<i});
        while(set.size()){
            auto [cst,cur,msk]=*set.begin();
            set.erase(*set.begin());
            if(msk+1==1<<n) return cst;
            for(int i:adj[cur]){
                set.insert({cst+1,i,msk|(1<<i)});
            }
        }
        return 0;
    }
};