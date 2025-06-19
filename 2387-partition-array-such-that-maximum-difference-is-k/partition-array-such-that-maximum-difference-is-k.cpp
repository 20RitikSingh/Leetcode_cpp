class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<bool> v(1e5+1);
        int last=nums[0],c=1;
        for(int i:nums) v[i]=1,last=min(last,i);
        for(int i=0;i<1e5+1;i++){
            if(i-last>k && v[i]){
                last=i;
                c++;
            }
        }
        return c;
    }
};