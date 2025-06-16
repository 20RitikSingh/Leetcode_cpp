class Solution {
    int dp[2000][2001];
    int rec(vector<int>&nums,int idx,int sum){
        if(idx==nums.size() || sum>=2000) return sum;
        if(dp[idx][sum]) return dp[idx][sum];
        int res=rec(nums,idx+1,sum);
        if(sum<nums[idx]) res=max(res,rec(nums,idx+1,sum+nums[idx]));
        dp[idx][sum]=res;
        return res;
    }
public:
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return rec(nums,0,0);
    }
};