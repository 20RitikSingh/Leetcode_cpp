class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i:nums){
            if(res.empty() || res.back().size()==3) res.push_back({});
            if(res.back().size() && i-res.back()[0]>k) return {};
            res.back().push_back(i);
        }
        return res;
    }
};