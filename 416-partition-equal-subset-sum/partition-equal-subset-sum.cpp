class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i:nums) sum+=i;
        if(sum%2) return 0;
        vector<bool> v(sum/2+1,0);
        v[0]=1;
        for(int i=0;i<n;i++){
            vector<bool> u=v;
            for(int j=0;j<sum/2+1;j++){
                if(v[j] && nums[i]+j<sum/2+1) u[nums[i]+j]=1;
            }
            v=u;
        }
        return v[sum/2];
    }
};