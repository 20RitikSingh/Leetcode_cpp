class Solution {
    long long pow(long long x,long long y){
        if(y==0) return 1;
        long long t=pow(x,y/2);
        if(y%2) return x*t*t%1000000007;
        return t*t%1000000007;
    }
public:
    int countGoodNumbers(long long n) {
        long long res=1;
        res*=pow(4,n/2)%1000000007;
        res*=pow(5,n-n/2)%1000000007;
        return res%1000000007;
    }
};