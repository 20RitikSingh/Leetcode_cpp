class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> set;
        int c=0,mx=0,n=nums.size();
        for(int i:nums) set.insert(i);
        mx=set.size();
        set.clear();
        for(int i=0;i<n;i++){
            set.clear();
            for(int j=i;j<n;j++){
                set.insert(nums[j]);
                if(set.size()==mx) c++;
            }
        }
        return c;
    }
};