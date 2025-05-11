class Solution {
    int check(vector<int> &nums,int msk,int target){
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            if(msk&(1<<i)){ 
                sum+=nums[i];
            }
        }
        if(sum%target) return 0;
        return sum/target;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(1<<n),u(1<<n);
        int target=0;
        for(int i:nums) target+=i;
        if(target%k) return 0;
        target/=k;
        for(int i=0;i<1<<n;i++){
            u[i]=check(nums,i,target);
            if(!u[i]) continue;
            v[i]++;
            for(int j=0;j<i;j++){
                if(!u[j]) continue;
                if(u[j]+1==u[i] && (j&i)==j) v[i]=max(v[i],1+v[j]);
            }
            if(v[i]>=k) return 1; 
        }
        return 0;
    }
};