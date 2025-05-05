class mod {
    static const int MOD = 1000000007;
public:
    int val;
    mod(int x = 0) {
        val = ((x % MOD) + MOD) % MOD;
    }
    mod operator+(const mod &other) const {
        return mod((val + other.val) % MOD);
    }
    mod operator-(const mod &other) const {
        return mod(((val - other.val + MOD) % MOD));
    }
    mod operator*(const mod &other) const {
        return mod((1LL * val * other.val) % MOD);
    }
    operator int() const{
        return val;
    }
};

class Solution {
public:
    int numTilings(int n) {
        vector<mod> top(n+5),full(n+5);
        top[2]=1;
        full[1]=1;
        full[2]=2;
        for(int i=3;i<=n;i++){
            top[i]=top[i-1]+full[i-2];
            full[i]=full[i-1]+full[i-2]+top[i-1]+top[i-1];
        }
        return full[n];
    }
};