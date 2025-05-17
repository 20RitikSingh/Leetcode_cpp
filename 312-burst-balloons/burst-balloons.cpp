class Solution {
    int dp[302][302];
    int rec(vector<int> &nums,int l,int h){
        if(h-l==1) return nums[l-1]*nums[l]*nums[h];
        if(dp[l][h]!=-1) return dp[l][h];
        dp[l][h]=0;
        for(int i=l;i<h;i++){
            dp[l][h]=max(dp[l][h],rec(nums,l,i)+nums[l-1]*nums[i]*nums[h]+rec(nums,i+1,h));
        }
        return dp[l][h];
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> v={1};
        memset(dp,-1,sizeof(dp));
        for(int i:nums) v.push_back(i);
        v.push_back(1);
        return rec(v,1,n+1);
    }
};