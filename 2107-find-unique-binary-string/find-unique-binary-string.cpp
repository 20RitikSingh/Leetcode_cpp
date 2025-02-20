class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        for(int i=0;i<nums[0].size();i++) nums[0][i]=((nums[i][i]-'0')+1)%2+'0';
        return nums[0];
    }
};