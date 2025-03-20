class Solution {
    bool check(vector<int> &nums, vector<vector<int>>& q,int k){
        vector<int> u(nums.size()+1);
        for(int i=0;i<k;i++){
            int l=q[i][0];
            int r=q[i][1];
            int v=q[i][2];
            u[l]-=v;
            u[r+1]+=v;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i>0) u[i]+=u[i-1];
            if(nums[i]+u[i]>0) return 0;
        }
        return 1;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0,high=queries.size();
        if(!check(nums,queries,high)) return -1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,queries,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};