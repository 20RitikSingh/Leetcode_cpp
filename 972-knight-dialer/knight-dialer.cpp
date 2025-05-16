class Solution {
    vector<vector<int>> adj={
        {4,6},
        {8,6},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };
    int mod=1e9+7;
    int dp[10][5001];
    int rec(int curr,int n){
        if(n<=0) return 1;
        if(dp[curr][n]!=0) return dp[curr][n];
        long long res=0;
        for(int i:adj[curr]){
            res=(res+rec(i,n-1))%mod;
        }
        dp[curr][n]=res;
        return res;
    }
public:
    int knightDialer(int n) {
        long long res=0;
        for(int i=0;i<10;i++){
            res+=rec(i,n-1);
            res%=mod;
        }
        return res;
    }
};