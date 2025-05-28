class Solution {
public:
    int differenceOfSums(int n, int m) {
        int t=n/m;
        t=m*(t*(t+1));
        n=n*(n+1)/2;
        return n-t;
    }
};