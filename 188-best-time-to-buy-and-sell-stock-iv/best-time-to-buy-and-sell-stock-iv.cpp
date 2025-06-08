class Solution {
    int dp[201][1001][2];
    int rec(vector<int> &nums,int k,int idx,bool f){
        if(k==0 || idx==nums.size()) return k%2?-1e9:0;
        if(dp[k][idx][f]!=-1) return dp[k][idx][f];
        dp[k][idx][f]=rec(nums,k,idx+1,f);
        if(f) dp[k][idx][f]=max(dp[k][idx][f],rec(nums,k-1,idx+1,0)+nums[idx]);
        else dp[k][idx][f]=max(dp[k][idx][f],rec(nums,k-1,idx+1,1)-nums[idx]);
        return dp[k][idx][f];
    }
public:
    int maxProfit(int k, vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,2*k,0,0);
    }
};