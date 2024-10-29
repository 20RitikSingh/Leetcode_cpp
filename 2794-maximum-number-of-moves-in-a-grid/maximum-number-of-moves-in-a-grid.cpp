class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int mx=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                // cout<<j<<" "<<i<<endl;
                if(j+1<n && grid[j][i]<grid[j+1][i+1]) dp[j][i]=max(dp[j][i],dp[j+1][i+1]+1);
                if(grid[j][i]<grid[j][i+1]) dp[j][i]=max(dp[j][i],dp[j][i+1]+1);
                if(j-1>=0 && grid[j][i]<grid[j-1][i+1]) dp[j][i]=max(dp[j][i],dp[j-1][i+1]+1);
            }
        }
        // for(auto i:dp){
        //     for(int j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            mx=max(mx,dp[i][0]);
        }
        return mx;
    }
};