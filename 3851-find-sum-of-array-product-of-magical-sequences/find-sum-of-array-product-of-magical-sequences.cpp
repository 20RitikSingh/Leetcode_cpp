class Solution {
    int pow(int x, int y) {
        if (y == 0) return 1;
        int res = pow(x, y / 2);
        res = (1LL * res * res) % mod;
        if (y % 2) res = (1LL * res * x) % mod;
        return res;
    }
    int inv(int n){
        return pow(n,mod-2);
    }
    int dp[31][31][51][60];
    int fact[31],invfact[31];
    int mod=1e9+7;
    int n;
    int rec(vector<int> &nums,int k,int m,int rm,int msk,int idx,int bits){
        if(idx==n){
            if(rm==0 && __builtin_popcount(msk)+bits==k) return fact[m];
            return 0;
        }

        if(dp[rm][msk][idx][bits]!=-1) return dp[rm][msk][idx][bits];

        int newbits=msk%2;
        int newmsk=msk/2;

        int res=0;
        for(int i=0;i<=rm;i++){
            int t=(1LL*pow(nums[idx],i)*invfact[i])%mod;
            res+=(1LL*rec(nums,k,m,rm-i,newmsk+i,idx+1,bits+newbits)*t)%mod;
            res%=mod;
        }
        dp[rm][msk][idx][bits]=res;
        return res;
    }
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        fact[0]=1,invfact[0]=1;
        for(int i=1;i<31;i++){ 
            fact[i]=(1LL*fact[i-1]*i)%mod;
            invfact[i]=inv(fact[i]);
        }
        return rec(nums,k,m,m,0,0,0);
    }
};