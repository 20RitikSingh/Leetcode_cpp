class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return 0;
        sum/=k;
        unordered_map<int,int> dp;
        dp[0]=0;
        for(int i=0;i<(1<<n) && !dp.count((1<<n)-1);i++){
            for(int j=0;j<n && dp.count(i) && !dp.count((1<<n)-1);j++){
                if((i&(1<<j))==0 && dp[i]+nums[j]<=sum) dp[i|(1<<j)]=(dp[i]+nums[j])%sum;
            }
        }
        return dp.count((1<<n)-1);
        
    }
};