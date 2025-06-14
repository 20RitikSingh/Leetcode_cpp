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
    int dp[16][1<<14];
    int rec(vector<int> &nums,int k,int msk){
        int n=nums.size(),res=1e9;
        if(msk+1==1<<n) return 0;
        if(dp[k][msk]) return dp[k][msk];
        for(int i=1;i<(1<<n);i++){
            if((msk&i)==0 && check(nums,k,i)){
                res=min(res,rec(nums,k,msk|i)+1);
            }
        }
        dp[k][msk]=res;
        return res;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        return rec(tasks,sessionTime,0);
    }
};