class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<bool> set(101);
        for(int i=n-1;i>=0;i--){
            if(set[nums[i]]) return i/3+1;
            set[nums[i]]=1;
        }
        return 0;
    }
};