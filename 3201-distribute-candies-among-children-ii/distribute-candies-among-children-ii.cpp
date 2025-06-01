class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res=0;
        for(int i=min(n,limit);i>=0;i--){
            if(n-i>2LL*limit) break;
            res+=max(0,min(n-i,limit)-max(0,n-i-limit)+1);
        }
        return res;
    }
};