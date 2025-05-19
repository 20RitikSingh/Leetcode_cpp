class Solution {
    int dp[500][500];
public:
    int minDistance(string s, string t,int i=0,int j=0) {
        if(i==s.size() || j==t.size()) return max(s.size()-i,t.size()-j);
        if(!dp[i][j]) dp[i][j]=min(minDistance(s,t,i+1,j+1)+(s[i]!=t[j]),min(minDistance(s,t,i+1,j)+1,minDistance(s,t,i,j+1)+1));
        return dp[i][j];
    }
};