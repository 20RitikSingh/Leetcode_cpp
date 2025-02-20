class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s=nums[0];
        int n=nums[0].size();
        for(int i=0;i<n;i++){
            s[i]=((nums[i][i]-'0')+1)%2+'0';
        }
        return s;
    }
};