const int MOD = 1e9 + 7;
const int MAXN = 100000;
long long fact[100001], invFact[100001];

long long power(int x,int y){
    if(y==0) return 1;
    long long res=power(x,y/2);
    res=res*res%MOD;
    if(y%2) res=res*x%MOD;
    return res;
}
struct Pre{
    Pre(){
        fact[0] = 1;
        for (int i = 1; i <= MAXN; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[MAXN] = power(fact[MAXN], MOD - 2);        
        for (int i = MAXN; i > 0; --i)         
            invFact[i - 1] = invFact[i] * i % MOD;
    }
};
Pre init;
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        return m*power(m-1,n-k-1)%MOD*fact[n-1]%MOD * invFact[k] % MOD * invFact[n -1-k] % MOD;;
    }
};
