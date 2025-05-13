class Solution {
    int dp[100001];
    int rec(int t){
        if(dp[t]!=-1) return dp[t];
        int res=0,mod=1e9+7;
        string s="ab";
        for(char ch:s){
            if(ch+t<='z') res=(res+1)%mod;
            else res=(1LL+res+rec(t-'z'+ch-1)-1)%mod;
        }
        dp[t]=res;
        return res;
    }
public:
    int lengthAfterTransformations(string s, int t) {
        int res=0,mod=1e9+7;
        memset(dp,-1,sizeof(dp));
        for(char ch:s){
            if(ch+t<='z') res=(res+1)%mod;
            else res=(1LL+res+rec(t-'z'+ch-1)-1)%mod;
        }
        return res;
    }
};