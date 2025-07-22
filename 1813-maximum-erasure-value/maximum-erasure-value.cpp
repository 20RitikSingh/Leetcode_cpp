class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size(),last=0,res=0;
        vector<int> pre(n+1);
        unordered_map<int,int> mp; 
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
            if(mp.count(nums[i]) && mp[nums[i]]>=last) last=mp[nums[i]]+1;
            else res=max(res,pre[i+1]-pre[last]);
            mp[nums[i]]=i;
        }
        return res;
    }
};