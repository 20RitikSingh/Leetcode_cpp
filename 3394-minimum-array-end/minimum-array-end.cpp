class Solution {
public:
    long long minEnd(long long n, long long x) {
        n--;
        for(int i=0;i<64;i++){
            if((x>>i)&1) continue;
            x|=(n&1)<<i;
            n/=2; 
        } 
        return x;
    }
};