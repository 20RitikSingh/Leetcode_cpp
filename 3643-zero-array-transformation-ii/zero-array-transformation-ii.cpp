class Solution {
    bool check(vector<int>& nums, vector<vector<int>>& queries,int k) {
        int n=nums.size();
        vector<int> v(n+1);
        for(int i=0;i<k;i++) 
            v[queries[i][0]]+=queries[i][2],v[queries[i][1]+1]-=queries[i][2];
        if(v[0]<nums[0]) return 0;
        for(int i=1;i<n;i++){ v[i]+=v[i-1]; if(v[i]<nums[i]) return 0;}
        return 1;

    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low=0,high=queries.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,queries,mid)) high=mid;
            else low=mid+1;
        }
        if(check(nums,queries,low)) return low;
        return -1;
    }
};