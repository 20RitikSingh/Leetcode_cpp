class Solution {
    int popdp[51];
    int popd(int x){
        if(popdp[x]) return popdp[x];
        int c=0,y=x;
        while(x!=1){ 
            if(popdp[x]) return popdp[y]=popdp[x]+c;
            x=__popcount(x),c++;
        }
        return popdp[y]=c;
    }
    long long dp[51][52][2];
    long long count(long long limit,int b,int pos=0,bool tight=0){
        if(1LL<<pos>limit || b<0) return (b || tight)?0:1;
        if(dp[b][pos][tight]!=-1) return dp[b][pos][tight];
        return dp[b][pos][tight]=count(limit,b,pos+1,(1LL<<pos)&limit?0:tight)
        +count(limit,b-1,pos+1,(1LL<<pos)&limit?tight:1);
    }
public:
    long long popcountDepth(long long n, int k) {
        if(!k) return 1;
        long long res=0;
        memset(dp,-1,sizeof(dp));
        for(long long i=1;i<51;i++) if(popd(i)==k-1 && (1LL<<i)-1<=n) res+=count(n,i)-(i==1);
        return res;
    }
};