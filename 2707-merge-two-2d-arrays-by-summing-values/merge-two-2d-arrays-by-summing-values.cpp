class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<int> v(1001);
        for(auto i:nums1){
            v[i[0]]+=i[1];
        }
        for(auto i:nums2){
            v[i[0]]+=i[1];
        }
        vector<vector<int>> res;
        for(int i=0;i<1001;i++){
            if(v[i]) res.push_back({i,v[i]});
        }
        return res;
    }
};