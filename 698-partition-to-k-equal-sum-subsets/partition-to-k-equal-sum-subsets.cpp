class Solution {
    int subsetSum(vector<int> &nums,int msk){
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            if(msk&(1<<i)){ 
                sum+=nums[i];
            }
        }
        return sum;
    }
    int dp[17][66000];
    bool rec(vector<vector<int>> &adj,int curr,int prev,int k){
        if(curr>k) return 1;
        if(dp[curr][prev]>=0) return dp[curr][prev];
        dp[curr][prev]=0;
        for(int i:adj[curr]){
            if((i&prev)!=prev || i<prev) continue;
            if(rec(adj,curr+1,i,k)){dp[curr][prev]=1; return 1;}
        }
        return 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> adj(k+1);
        memset(dp,-1,sizeof(dp));
        int target=0;
        for(int i:nums) target+=i;
        if(target%k) return 0;
        target/=k;

        for(int i=0;i<1<<n;i++){
            int x=subsetSum(nums,i);
            if(x%target) continue;
            adj[x/target].push_back(i);
        }
        return rec(adj,1,0,k);
    }
};