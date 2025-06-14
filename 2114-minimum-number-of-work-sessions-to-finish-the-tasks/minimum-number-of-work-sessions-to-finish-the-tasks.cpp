class Solution {
    int dp2[1<<14];
    int check(vector<int> &nums,int k,int msk){
        int sum=0;
        if(dp2[msk]) return dp2[msk]-1;
        for(int i=0;i<nums.size();i++){
            if(msk&(1<<i)) sum+=nums[i];
        }
        dp2[msk]=1+(sum<=k);
        return sum<=k;
    }
    int dp[1<<14];
    int rec(vector<int> &nums,int k,int msk){
        int n=nums.size(),res=1e9;
        if(msk+1==1<<n) return 0;
        if(dp[msk]) return dp[msk];
        int subset = ((1 << n) - 1) ^ msk;
        for (int sub = subset; sub>0; sub = (sub - 1) & subset) {
            if (check(nums, k, sub)) {
                res = min(res, rec(nums, k, msk | sub) + 1);
            }
        }
        dp[msk]=res;
        return res;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.begin(),tasks.end(),greater<int>());
        return rec(tasks,sessionTime,0);
    }
};