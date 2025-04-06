class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),mx=0;
        vector<int> res,chainLength(n,1),chainPrev(n,-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]) continue;
                if(chainLength[j]>chainLength[i]-1){
                    chainPrev[i]=j;
                    chainLength[i]=chainLength[j]+1;
                    if(chainLength[i]>chainLength[mx]) mx=i;
                }
            }
        }
        while(mx>=0){
            res.push_back(nums[mx]);
            mx=chainPrev[mx];
        }
        return res;
    }
};