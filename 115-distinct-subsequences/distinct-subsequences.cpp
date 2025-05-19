class Solution {
    int dp[1000][1000];
    int nxt[1000][60];
    int rec(string s,string t, int i,int j){
        if(j==t.size()) return 1;
        if(i==s.size() || t.size()-j>s.size()-i) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=0;

        int k=nxt[i][t[j]-'A'];
        if(k!=0) dp[i][j]+=rec(s,t,k,j);
        if(s[i]==t[j]) dp[i][j]+=rec(s,t,i+1,j+1);
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        for(int i=s.size()-2;i>=0;i--){
            for(int j=0;j<60;j++) nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i+1]-'A']=i+1;
        }
        return rec(s,t,0,0);
    }
};