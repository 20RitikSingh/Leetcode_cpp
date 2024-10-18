class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size(),mx=0;
        for(int i:nums) mx|=i;
        vector<int> v(mx+1);
        v[0]++;
        for(int i=0;i<n;i++){
            vector<int> t(mx+1);
            for(int j=0;j<=mx;j++){
                if(v[j]) t[j|nums[i]]+=v[j];
                t[j]+=v[j];
            }
            v=t;
        }
        return v[mx];
    }
};