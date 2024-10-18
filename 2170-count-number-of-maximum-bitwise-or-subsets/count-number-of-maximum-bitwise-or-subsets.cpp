class Solution {
    int res=0,target=0;
    void rec(vector<int> &nums,int vis,int curr){
        int n=nums.size();
        if(curr==n){
            int x=0;
            for(int i=0;i<n;i++){
                if(vis&(1<<i))
                    x|=nums[i];
            }
            if(x==target) res++;
            return;
        }
        rec(nums,vis,curr+1);
        rec(nums,vis|(1<<curr),curr+1);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        for(int i:nums) target|=i;
        rec(nums,0,0);
        return res;
    }
};