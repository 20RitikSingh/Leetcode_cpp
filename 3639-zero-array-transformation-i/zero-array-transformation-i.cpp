class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> v(n+1);
        for(auto q:queries) v[q[0]]++,v[q[1]+1]--;
        if(v[0]<nums[0]) return 0;
        for(int i=1;i<n;i++){ v[i]+=v[i-1]; if(v[i]<nums[i]) return 0;}
        return 1;

    }
};