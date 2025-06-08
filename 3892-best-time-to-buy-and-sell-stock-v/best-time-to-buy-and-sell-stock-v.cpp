class Solution {
    long long dp[1001][1001][4];
    long long rec(vector<int> &nums,long long k,long long idx,long long f){
        if(k==0 || idx==nums.size()) return k%2?-1e15:0;
        if(dp[k][idx][f]!=-1) return dp[k][idx][f];
        dp[k][idx][f]=rec(nums,k,idx+1,f);

        if(f==0){ 
            dp[k][idx][f]=max(dp[k][idx][f],rec(nums,k-1,idx+1,1)+nums[idx]);
            dp[k][idx][f]=max(dp[k][idx][f],rec(nums,k-1,idx+1,2)-nums[idx]);
        }
        if(f==1){ 
            dp[k][idx][f]=max(dp[k][idx][f],rec(nums,k-1,idx+1,0)-nums[idx]);
        }
        if(f==2){ 
            dp[k][idx][f]=max(dp[k][idx][f],rec(nums,k-1,idx+1,0)+nums[idx]);
        }
        return dp[k][idx][f];
    }
public:
    long long maximumProfit(vector<int>& nums,long long k) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,2*k,0,0);
    }
};