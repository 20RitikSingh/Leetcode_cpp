class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges,long long res=0,int mi=1e9,bool c=0) {
        for(int i=0;i<nums.size();res+=max(nums[i],nums[i]^k),mi=min(mi,abs((nums[i]^k)-nums[i])),c=(c+(nums[i]<=(nums[i]^k)))%2,i++);
        return res-c*mi;
    }
};