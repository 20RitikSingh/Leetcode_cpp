class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res=0;
        int mx=-1e9,c=0;
        for(int i:nums){
            res+=max(i,i^k);
            mx=max(mx,0-abs((i^k)-i));
            c+=i<=(i^k);
        }
        if(c%2) res+=mx;
        return res;
    }
};