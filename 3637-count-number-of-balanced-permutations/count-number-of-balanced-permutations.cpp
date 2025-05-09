class Solution {
    int total=0;
    int n;
    int mod=1e9+7;
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
    int dp[81][361][81];
    int rec(vector<int> &v,int idx,int sum,int count){
        if(idx>=10){
            if(sum!=total/2 || count!=(n+1)/2) return 0;
            return (1LL*fact[n/2]*fact[(n+1)/2])%mod;
        }
        if (dp[idx][sum][count]>=0) return dp[idx][sum][count];

        int res=0;
        for(int i=0;i<=v[idx];i++){
            res+=1LL*rec(v,idx+1,sum+i*idx,count+i)*(1LL*invfact[i]*invfact[v[idx]-i]%mod)%mod;
            res%=mod;
        }

        dp[idx][sum][count] = res;
        return res;
    }
    int fact[81],invfact[81];
public:
    int countBalancedPermutations(string num) {
        fact[0]=1;
        invfact[0]=1;
        memset(dp, -1, sizeof(dp));
        for(int i=1;i<81;i++){
            fact[i]=(1LL*i*fact[i-1])%mod;
            invfact[i]=inv(fact[i]);
        }
        vector<int> v(10);
        n=num.size();
        for(int i=0;i<n;i++){ 
            total+=num[i]-'0';
            v[num[i]-'0']++;
        }
        if(total%2) return 0;
        return rec(v,0,0,0);
    }
};