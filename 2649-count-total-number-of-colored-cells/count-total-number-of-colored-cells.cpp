class Solution {
public:
    long long coloredCells(int n) {
        long long res=1;
        n--;
        res+=2LL*n*(1+n);
        return res;
    }
};

// 4 8 12 