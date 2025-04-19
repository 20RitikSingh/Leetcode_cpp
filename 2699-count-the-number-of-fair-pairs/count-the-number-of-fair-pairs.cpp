class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long c=0,n=nums.size();
        for(int i=0;i<n;i++){
            c+=upper_bound(nums.begin(),nums.end(),upper-nums[i])-lower_bound(nums.begin(),nums.end(),lower-nums[i])-(nums[i]>=lower-nums[i] && nums[i]<=upper-nums[i]);
        }
        return c/2;
    }
};