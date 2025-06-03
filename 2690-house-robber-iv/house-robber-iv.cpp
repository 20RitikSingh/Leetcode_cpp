class Solution {
    bool check(vector<int> &nums,int k,int mi){
        int n=nums.size();
        vector<int> v(n);
        v[0]=(nums[0]<=mi);
        if(v[0]==k) return 1;
        for(int i=1;i<n;i++){
            v[i]=nums[i]<=mi;
            if(i>1) v[i]+=v[i-2];
            v[i]=max(v[i],v[i-1]);
            if(v[i]>=k) return 1;
        }
        return 0;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low=1,high=1e9;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(nums,k,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};