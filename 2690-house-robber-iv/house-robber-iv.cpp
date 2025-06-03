class Solution {
    bool check(vector<int> &nums,int k,int mi){
        int n=nums.size();
        if(n<3){
            if(n==1 && k==1 ) return nums[0]<=mi;
            if(n==2 && k==1 ) return (nums[0]<=mi || nums[1]<=mi);
            return 0;
        }
        vector<int> v(n);
        v[0]=(nums[0]<=mi);
        v[1]=max(v[0],int(nums[1]<=mi));
        for(int i=2;i<n;i++){
            v[i]=max(v[i-2]+(nums[i]<=mi),v[i-1]);
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