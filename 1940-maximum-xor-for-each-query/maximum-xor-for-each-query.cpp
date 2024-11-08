class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask=(1<<maximumBit)-1,x=0,n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){ 
            x^=nums[i];
            res[n-i-1]=mask-x&mask;
        }
        return res;
    }
};