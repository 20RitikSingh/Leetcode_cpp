class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> set;
        for(int i=n-1;i>=0;i--){
            if(set.count(nums[i])) return i/3+1;
            set.insert(nums[i]);
        }
        return 0;
    }
};