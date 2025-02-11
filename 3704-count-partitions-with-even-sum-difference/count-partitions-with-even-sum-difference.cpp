class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0,c=0,s=0;
        for(int i:nums) sum+=i;
        for(int i=0;i<nums.size()-1;i++){
            s+=nums[i];
            if((sum-2*s)%2==0) c++;
        }
        return c;
    }
};