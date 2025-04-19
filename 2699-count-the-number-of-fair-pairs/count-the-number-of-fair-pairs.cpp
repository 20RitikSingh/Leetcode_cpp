class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=lower-nums[i] && nums[i]<=upper-nums[i]) c--;
            c+=upper_bound(nums.begin(),nums.end(),upper-nums[i])
            -lower_bound(nums.begin(),nums.end(),lower-nums[i]);
            // cout<<nums[i]<<" "<<c<<endl;
        }
        return c/2;
    }
};