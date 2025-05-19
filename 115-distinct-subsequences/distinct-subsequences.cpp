class Solution {
    int dp[1000][1000];
    int rec(string s,string t, int i,int j){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(t.size()-j>s.size()-i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=rec(s,t,i+1,j);
        if(s[i]==t[j]) dp[i][j]+=rec(s,t,i+1,j+1);
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return rec(s,t,0,0);
    }
};