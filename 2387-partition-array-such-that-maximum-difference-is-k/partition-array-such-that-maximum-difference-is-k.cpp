class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<int> v(1e5+1);
        for(int i:nums){
            v[i]++;
        }
        int last=*min_element(nums.begin(),nums.end()),c=1;
        for(int i=0;i<1e5+1;i++){
            if(i-last>k && v[i]){
                last=i;
                c++;
            }
        }
        return c;
    }
};