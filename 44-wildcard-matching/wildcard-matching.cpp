class Solution {
public:
    bool isMatch(string s, string t) {
        vector<vector<bool>> dp(2,vector<bool>(t.size()+1,0));
        dp[0][t.size()]=1;
        for(int j=t.size()-1;j>=0;j--) dp[0][j]=(t[j]=='*' && dp[0][j+1]);
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                dp[1][j]=((s[i]==t[j] || t[j]=='?') && dp[0][j+1])
                        ||(t[j]=='*' && (dp[0][j] || dp[1][j+1]));
            }
            dp[0]=dp[1];
            dp[1]=vector<bool>(t.size());
        }
        return dp[0][0];
    }
};