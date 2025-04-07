class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i:nums) sum+=i;
        if(sum%2) return 0;
        vector<bool> v(20001,0);
        v[0]=1;
        for(int i=0;i<n;i++){
            vector<bool> u=v;
            for(int j=0;j<20001;j++){
                if(v[j]) u[nums[i]+j]=1;
            }
            v=u;
        }
        return v[sum/2];
    }
};