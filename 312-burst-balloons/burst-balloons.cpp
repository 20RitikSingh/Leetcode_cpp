class Solution {
    int dp[301][301];
    int rec(vector<int> &nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int n=nums.size();
        if(i==j) return (i>0?nums[i-1]:1)*nums[i]*(i<n-1?nums[i+1]:1);
        int res=0;
        for(int k=i;k<=j;k++)
        res=max(res,(i>0?nums[i-1]:1)*nums[k]*(j<n-1?nums[j+1]:1)+rec(nums,i,k-1)+rec(nums,k+1,j));
        return dp[i][j]=res;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(nums,0,n-1);
    }
};