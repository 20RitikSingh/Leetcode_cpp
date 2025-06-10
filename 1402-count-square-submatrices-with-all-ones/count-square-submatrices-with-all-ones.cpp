class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i-1][j-1]-dp[i-1][j-1];
            }
        }
        auto check=[&](int a,int b,int c)->bool{
            if(a+c>m || b+c>n) return 0;
            return c*c==dp[a][b]+dp[a+c][b+c]-dp[a+c][b]-dp[a][b+c];
        };
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=1;k<=min(m,n);k++){
                    int x=check(i,j,k);
                    if(!x) break;
                    ans+=x;
                }
            }
        }
        return ans;
    }
};