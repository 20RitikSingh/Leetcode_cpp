class Solution {
    int checkdp[2001][2001];
    int check(string &s,int l,int h){
        if(checkdp[l][h]) return checkdp[l][h];
        for(int i=0;i<(h-l)/2;i++){
            if(s[l+i]!=s[h-i-1]){
                checkdp[l][h]=1;
                return 1;
            } 
        }
        checkdp[l][h]=2;
        return 2;
    }
    int dp[2001][2001];
    int rec(string &s, int l, int h){
        if(check(s,l,h)-1) return 0;
        if(dp[l][h]) return dp[l][h];
        dp[l][h]=1e9;
        for(int i=l;i<h;i++){
            if(check(s,l,i)-1)
            dp[l][h]=min(dp[l][h],rec(s,l,i)+rec(s,i,h)+1);
        }
        return dp[l][h];
    }
public:
    int minCut(string s) {
        return rec(s,0,s.size());
    }
};