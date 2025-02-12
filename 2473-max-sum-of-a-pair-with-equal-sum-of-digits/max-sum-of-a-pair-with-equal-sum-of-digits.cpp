class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int mx=-1;
        vector<int> v(82,-2e9);
        for(int i:nums){
            int x=0,j=i;
            while(i>0){
                x+=i%10;
                i/=10;
            }
            mx=max(j+v[x],mx);
            v[x]=max(j,v[x]);
        }
        return mx;
    }
};