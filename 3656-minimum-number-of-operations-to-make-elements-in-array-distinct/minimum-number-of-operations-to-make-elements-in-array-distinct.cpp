class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        bitset<101> set;
        for(int i=n-1;i>=0;set[nums[i]]=1,i--){
            if(set[nums[i]]) return i/3+1;
        }
        return 0;
    }
};