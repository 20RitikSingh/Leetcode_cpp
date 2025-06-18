class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bitset<4000> dp;
        dp[0]=1;
        for(int i:nums){
            for(int j=0;j<i;j++){
                if(dp[j]) dp[j+i]=1;
            }
        }
        for(int i=4000-1;i>=0;i--){
            if(dp[i]) return i;
        }
        return 0;
    }
};