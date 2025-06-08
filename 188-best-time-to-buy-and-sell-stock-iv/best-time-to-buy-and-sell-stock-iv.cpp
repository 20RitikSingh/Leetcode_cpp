class Solution {
    int dp[101][1001];
    int rec(vector<int> &nums,int k,int idx){
        int n=nums.size();
        if(!k || idx==n) return 0;
        if(dp[k][idx]!=-1) return dp[k][idx];
        dp[k][idx]=rec(nums,k,idx+1);
        for(int i=idx+1;i<n;i++){
            dp[k][idx]=max(dp[k][idx],rec(nums,k-1,i+1)+nums[i]-nums[idx]);
        }
        return dp[k][idx];
    }
public:
    int maxProfit(int k, vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,k,0);
    }
};