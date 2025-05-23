class Solution {
    long long dp[20000][2];
    long long rec(vector<int> &nums,int k,int idx,bool parity){
        if(idx==nums.size()){
            if(parity) return -1e15;
            return 0;
        }
        if(dp[idx][parity]==-1) dp[idx][parity]=max(rec(nums,k,idx+1,parity)+nums[idx],rec(nums,k,idx+1,!parity)+(nums[idx]^k));
        return dp[idx][parity];
    }
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,k,0,0);
    }
};