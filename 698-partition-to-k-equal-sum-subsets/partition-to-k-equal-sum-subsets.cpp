class Solution {
    int get(vector<int> &nums,int msk){
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(msk&(1<<i)){
                sum+=nums[i];
            }
        }
        return sum;
    }
    char dp[17][1<<16];
    bool rec(vector<vector<int>> &v,int idx,int msk){
        if(idx==v.size()) return 1;
        if(dp[idx][msk]!=-1) return dp[idx][msk];
        for(int i:v[idx]){
            if((msk&i)==msk && rec(v,idx+1,msk|i)){
                dp[idx][msk]=1;
                return 1;
            }
        }
        dp[idx][msk]=0;
        return 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return 0;
        sum/=k;
        vector<vector<int>> v(k+1);

        for(int i=1;i<(1<<n);i++){
            int x=get(nums,i);
            if(x%sum) continue;
            v[x/sum].push_back(i);
        }

        return rec(v,1,0);
        
    }
};