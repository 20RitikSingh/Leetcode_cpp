class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int mx=-1;
        vector<vector<int>> v(82);
        for(int i:nums){
            int x=0,j=i;
            while(i>0){
                x+=i%10;
                i/=10;
            }
            if(v[x].size()<2) v[x].push_back(j);
            else{
                if(v[x][0]<v[x][1]) swap(v[x][0],v[x][1]);
                v[x][1]=max(j,v[x][1]);
            }
            if(v[x].size()<2) continue;
            mx=max(mx,v[x][0]+v[x][1]);
        }
        return mx;
    }
};