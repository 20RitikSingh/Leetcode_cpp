#define MOD 1000000007
class Solution {
    int ncr(int n, int r){
        // code here
        int mod = 1000000007;
        if (r > n){
            return 0;
        }
        
        long long numerator = 1;
        long long denominator = 1;
        
        for (int i = 0; i < r; i++){
            numerator = (numerator * (n - i)) % mod;
            denominator = (denominator * (i + 1)) % mod;
        }
        
        // Calculate modular inverse of denominator
        long long inverse = 1;
        long long base = denominator;
        long long power = mod - 2;
        while (power > 0){
            if (power & 1){
                inverse = (inverse * base) % mod;
            }
            base = (base * base) % mod;
            power >>= 1;
        }
        
        // Calculate nCr modulo mod
        long long result = (numerator * inverse) % mod;
        return result;
    }
    int count(int l,int r,int n){
        long long res=1,c=0,k=r/l;
        while (k % 2 == 0) {
            c++;
            k = k/2; 
        }
        if(c>0) res*=ncr(c+n-2,c);
        res%=MOD;
        for (int i = 3; i*i <= k; i = i + 2) {
            c=0;
            while (k % i == 0) {
                c++;
                k = k/i; 
            } 
            if(c>0) res*=ncr(c+n-2,c);
            res%=MOD;
        } 
        if (k > 2) res*=n-1;
        res%=MOD;
        return res; 
    }
public:
    int idealArrays(int n, int mx) {
        int res=0;
        for(int i=1;i<=mx;i++){
            for(int j=i;j<=mx;j++){
                if(j%i) continue;
                res+=count(i,j,n)%MOD;
                res%=MOD;
            }
        }
        return res;
    }
};