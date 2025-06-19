class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        unordered_map<double,int> mp;
        for(int r=4;r<n;r++){ int q = r-2 ;
            for(int p = 0;p<q-1;p++) mp[1.0*nums[p]/nums[q]]++;
            for(int s = r+2;s<n;s++) res += mp[1.0*nums[s]/nums[r]];
        }
         

        return res;
    }
};