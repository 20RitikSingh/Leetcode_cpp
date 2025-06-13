class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> set;
        for(int i:nums){
            auto it=set.lower_bound(i);
            if(it!=set.end()) set.erase(it);
            set.insert(i);
        }
        return set.size();
    }
};