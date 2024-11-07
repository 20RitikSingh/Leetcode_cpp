class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i:nums){
            auto it=lower_bound(v.begin(),v.end(),i);
            if(it!=v.end()){
                *it=i;
            }else v.push_back(i);
        }
        return v.size();
    }
};