class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return 0;
        sum/=k;
        vector<int> dp(1<<n,-1);
        dp[0]=0;
        for(int i=0;i<(1<<n);i++){
            // cout<<bitset<10>(i)<<" "<<dp[i]<<endl;
            for(int j=0;j<n && dp[i]>=0;j++){
                if(i&(1<<j) || dp[i]+nums[j]>sum) continue;
                if((i|(1<<j))+1==1<<n) return 1;
                dp[i|(1<<j)]=(dp[i]+nums[j])%sum;
            }
        }
        return 0;
        
    }
};