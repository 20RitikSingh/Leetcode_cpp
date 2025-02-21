class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx=0,n=nums.size(),sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                mx=max(sum,mx);
                sum=nums[i];
            }else sum+=nums[i];
        }
        return max(mx,sum);
    }
};