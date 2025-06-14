class Solution {
    int check(vector<int> &nums,int p,int d){
        for(int i=1;i<nums.size() && p>0;i++) if(nums[i]-nums[i-1]<=d) p--,i++;
        return p<=0;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0,high=nums.back();
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,p,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};