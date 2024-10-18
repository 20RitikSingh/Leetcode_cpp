class Solution {
    int res=0,target=0;
    void rec(vector<int> &nums,int curr,int x){
        int n=nums.size();
        if(curr==n){
            if(x==target) res++;
            return;
        }
        rec(nums,curr+1,x);
        rec(nums,curr+1,x|nums[curr]);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for(int i:nums) target|=i;
        rec(nums,0,0);
        return res;
    }
};