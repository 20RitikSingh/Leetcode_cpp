class Solution {

    const int MOD = 1e9 + 7;

    long long fact[100001], invFact[100001];
    long long power(long long a, long long b) {
        long long res = 1;
        while(b > 0) {
            if(b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precompute(int n) {
        fact[0] = invFact[0] = 1;
        for(int i = 1; i <=n; ++i) {
            fact[i] = fact[i-1] * i % MOD;
            invFact[i] = power(fact[i], MOD - 2);
        }
    }

public:
    int countGoodArrays(int n, int m, int k) {
        precompute(max(m,n));
        return m*power(m-1,n-k-1)%MOD*fact[n-1]%MOD * invFact[k] % MOD * invFact[n -1-k] % MOD;;
    }
};
