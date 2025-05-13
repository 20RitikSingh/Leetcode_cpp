int dp[100001],mod=1e9+7;
long long rec(int t){
    if(t<0) return 1;
    if(dp[t]==0) dp[t]=(dp[t]+rec(t-26)+rec(t-25))%mod;
    return dp[t];
}
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int res=0;
        for(char ch:s) res=(res+rec(t-'z'+ch-1))%mod;
        return res;
    }
};