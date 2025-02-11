class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum%2) return 0;
        return nums.size()-1;
    }
};