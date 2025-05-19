class Solution {
    int dp[500][500];
    int rec(string s,string t,int i,int j){
        if(i==s.size()) return t.size()-j;
        if(j==t.size()) return s.size()-i;
        if(!dp[i][j]) 
        dp[i][j]=min(rec(s,t,i+1,j+1)+(s[i]!=t[j]),min(rec(s,t,i+1,j)+1,rec(s,t,i,j+1)+1));
        return dp[i][j];
    }
public:
    int minDistance(string word1, string word2) {
        return rec(word1,word2,0,0);
    }
};