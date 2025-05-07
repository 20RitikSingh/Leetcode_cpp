class Solution {
    int pow(int x,int y,int m){
        if(!y) return 1; 
        int r=pow(x,y/2,m);
        if(y%2) return (((1LL*r*r)%m)*x)%m;
        else return (1LL*r*r)%m;
    }
    int digits(int n){
        int c=0;
        for(;n>0;c++,n/=10);
        return c;
    }
    vector<int> v;
    int dp[9000000];
    int rec(vector<int> &nums,int &msk,int k,int r){
        if(dp[msk*1000+r]>=0) return dp[msk*1000+r];
        bool f=0;
        for(int i=0;i<nums.size();i++){
            if(msk&(1<<i)) continue;
            f=1;
            msk=msk|(1<<i);
            int x=(1LL*r*pow(10,digits(nums[i]),k)+nums[i])%k;
            if(rec(nums,msk,k,x)==0){
                v.push_back(nums[i]);
                return 0;
            }
            msk=msk^(1<<i);
        }
        if(f){dp[msk*1000+r]=1; return 1;}
        dp[msk*1000+r]=r;
        return r;
    }
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int msk=0;
        fill(begin(dp),end(dp),-1);
        rec(nums,msk,k,0);
        if(v.size()<nums.size()) v.clear();
        reverse(v.begin(),v.end());
        return v;
    }
};