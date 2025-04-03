class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long mx=nums[0],diff=0,res=0,n=nums.size();
        for(int i=1;i<n;i++){
            mx=max(mx,1LL*nums[i]);
            res=max(res,diff*1LL*nums[i]);
            diff=max(diff,mx-nums[i]);
        }
        return res;
    }
};