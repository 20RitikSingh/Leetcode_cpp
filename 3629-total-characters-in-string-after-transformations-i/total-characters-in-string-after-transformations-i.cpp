class Solution {
    int dp[100001],mod=1e9+7,res=0;
public:
    int lengthAfterTransformations(string s, int t) {
        if(s=="ab" && t<0) return 1;
        if(s=="ab" && dp[t]==0) dp[t]=(0LL+dp[t]+lengthAfterTransformations("ab",t-26)+lengthAfterTransformations("ab",t-25))%mod;
        if(s=="ab")return dp[t];
        for(char ch:s) res=(0LL+res+lengthAfterTransformations("ab",t-'z'+ch-1))%mod;
        return res;
    }
};