class Solution {
    vector<int> dp,req;
    int rec(int msk,vector<int> &s){
        if(dp[msk]!=-1) return dp[msk];
        int res=0,idx=__builtin_popcount(msk) + 1;
        for(int i=0;i<s.size();i++){
            if(msk&(1<<i) || (msk&req[i])<req[i]) continue;
            res=max(res,rec(msk|(1<<i),s)+idx*s[i]);
        }
        dp[msk]=res;
        return res;
    }
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& s) {
        req.resize(n);
        dp.resize(1<<n,-1);
        for(auto e:edges) req[e[1]]|=1<<e[0];
        return rec(0,s);
        return 0;
    }
};