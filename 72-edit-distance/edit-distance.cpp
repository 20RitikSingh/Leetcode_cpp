class Solution {
    int dp[500][500];
    int rec(string s,string t,int i,int j){
        if(i==s.size()) return t.size()-j;
        if(j==t.size()) return s.size()-i;
        if(dp[i][j]) return dp[i][j];
        dp[i][j]=rec(s,t,i+1,j+1)+(s[i]!=t[j]);
        dp[i][j]=min(dp[i][j],rec(s,t,i+1,j)+1);
        dp[i][j]=min(dp[i][j],rec(s,t,i,j+1)+1);
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        // memset(dp,-1,sizeof(dp));
        return rec(word1,word2,0,0);
    }
};