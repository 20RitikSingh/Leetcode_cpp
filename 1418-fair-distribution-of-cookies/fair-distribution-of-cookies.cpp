class Solution {
    int dp2[1<<8];
    int sum(vector<int> &nums,int msk){
        if(!msk || dp2[msk]!=0) return dp2[msk];
        int s=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(msk&(1<<i)) s+=nums[i];
        }
        dp2[msk]=s;
        return s;
    }
    int dp[9][1<<8];
    int rec(vector<int>& nums,int k,int msk){
        int res=1e9,n=nums.size();
        if(msk+1==1<<n) return 0;
        if(k<=0) return 1e9;
        if(dp[k][msk]!=-1) return dp[k][msk];
        int subset = ((1 << n) - 1) ^ msk;
        for (int sub = subset; sub; sub = (sub - 1) & subset) {
            res=min(res,max(sum(nums,sub),rec(nums,k-1,sub|msk)));
        }
        dp[k][msk]=res;
        return res;
    }
public:
    int distributeCookies(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,k,0);
    }
};