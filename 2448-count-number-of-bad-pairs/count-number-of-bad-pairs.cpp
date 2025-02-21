class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            // cout<<nums[i]-i<<" ";
            mp[nums[i]-i]++;
        }
        long long res=0;
        for(auto [k,f]:mp){
            res+=1LL*(n-f)*f;
        }
        return res/2;
    }
};