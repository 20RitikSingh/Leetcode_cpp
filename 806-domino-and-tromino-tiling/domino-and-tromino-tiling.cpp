class Solution {
public:
    int numTilings(int n) {
        int mod=1e9+7;
        vector<int> top(n+5),full(n+5);
        top[2]=1;
        full[1]=1;
        full[2]=2;
        for(int i=3;i<=n;i++){
            top[i]=(1LL*top[i-1]+full[i-2])%mod;
            full[i]=(1LL*full[i-1]+full[i-2]+top[i-1]+top[i-1])%mod;
        }
        return full[n];
    }
};