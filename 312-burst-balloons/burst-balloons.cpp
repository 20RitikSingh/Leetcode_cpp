class Solution {
    int dp[302][302];
    vector<int> nums={1};
    int rec(int l,int h){
        if(l==h) return 0;
        if(h-l==1) return nums[l-1]*nums[l]*nums[h];
        if(dp[l][h]) return dp[l][h];
        dp[l][h]=0;
        for(int i=l;i<h;i++) dp[l][h]=max(dp[l][h],rec(l,i)+nums[l-1]*nums[i]*nums[h]+rec(i+1,h));
        return dp[l][h];
    }
public:
    int maxCoins(vector<int>& v) {
        for(int i:v) nums.push_back(i);
        nums.push_back(1);
        return rec(1,v.size()+1);
    }
};