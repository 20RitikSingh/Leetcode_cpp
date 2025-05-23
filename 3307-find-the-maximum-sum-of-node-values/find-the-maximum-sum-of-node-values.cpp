struct Solution{
    long long maximumValueSum(
        vector<int>& n, int k, vector<vector<int>>& edges,
        long res=0,int mi=1e9,bool c=0
        ){
            for(
                int i=0;
                i<n.size();
                res+=max(n[i],n[i]^k),
                mi=min(mi,abs((n[i]^k)-n[i])),
                c=(c+(n[i]<=(n[i]^k)))%2,
                i++
            );
        return res-c*mi;
    }
};