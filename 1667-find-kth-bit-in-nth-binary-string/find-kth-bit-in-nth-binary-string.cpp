class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int t=pow(2,n-1);
        if(k==t) return '1';
        if(k>t) return findKthBit(n-1,2*t-k)=='0'?'1':'0';
        return findKthBit(n-1,k);
    }
};