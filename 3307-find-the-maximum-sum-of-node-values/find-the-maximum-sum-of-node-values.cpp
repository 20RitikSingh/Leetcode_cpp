class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res=0;
        int mx=-1e9,c=0;
        for(int i:nums){
            if(i>(i^k)){
                res+=i;
                mx=max(mx,(i^k)-i);
            }
            else{
                c++;
                res+=i^k;
                mx=max(mx,i-(i^k));
            }
        }
        if(c%2) res+=mx;
        return res;
    }
};