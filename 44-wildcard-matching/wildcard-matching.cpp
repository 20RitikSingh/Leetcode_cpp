class Solution {
public:
    bool isMatch(string s, string t) {
        if(s.empty()){
            for(char ch:t) if(ch!='*') return 0;
            return 1;
        }
        vector<vector<bool>> dp(s.size()+1,vector<bool>(t.size()+1,0));
        dp[s.size()][t.size()]=1;
        for(int j=t.size()-1;j>=0;j--){
            dp[s.size()][j]=(t[j]=='*' && dp[s.size()][j+1]);
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=t.size()-1;j>=0;j--){
                dp[i][j]=((s[i]==t[j] || t[j]=='?') && dp[i+1][j+1])
                        ||(t[j]=='*' && (dp[i+1][j] || dp[i][j+1]));
            }
        }
        return dp[0][0];
    }
};