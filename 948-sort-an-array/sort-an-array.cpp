class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        multiset<int> set(nums.begin(),nums.end());
        for(int &i:nums){ 
            i=*set.begin();
            set.erase(set.begin());
        }
        return nums;
    }
};