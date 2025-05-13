long long rec(int t){
    static int dp[100001];
    if(t<0) return 1;
    if(!dp[t]) dp[t]=(dp[t]+rec(t-26)+rec(t-25))%1000000007;
    return dp[t];
}
struct Solution {
    int lengthAfterTransformations(string s, int t,int res=0) {
        for(char ch:s) res=(res+rec(t-'z'+ch-1))%1000000007;
        return res;
    }
};