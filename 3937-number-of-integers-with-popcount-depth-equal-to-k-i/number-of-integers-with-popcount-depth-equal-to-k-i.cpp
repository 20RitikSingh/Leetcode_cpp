class Solution {
    int popdp[51];
    int popd(int x){
        if(popdp[x]) return popdp[x];
        int c=0;
        while(x!=1){
            x=__popcount(x);
            c++;
        }
        return popdp[x]=c;
    }
    long long dp[51][52][2];
    long long count(long long limit,int b,int pos=0,bool tight=0){
        if(b<0) return 0;
        if(1LL<<pos>limit){
            if(b || tight) return 0;
            return 1;
        }
        if(dp[b][pos][tight]!=-1) return dp[b][pos][tight];
        return dp[b][pos][tight]=count(limit,b,pos+1,(1LL<<pos)&limit?0:tight)
        +count(limit,b-1,pos+1,(1LL<<pos)&limit?tight:1);
    }
public:
    long long popcountDepth(long long n, int k) {
        if(!k) return 1;
        vector<int> v;
        for(long long i=1;i<51;i++){
            int d=popd(i);
            if(d==k-1 && (1LL<<i)-1<=n) v.push_back(i);
        }
        long long res=0;
        memset(dp,-1,sizeof(dp));
        for(int i:v){
            res+=count(n,i);
            if(i==1) res--;
        }
        return res;
    }
};