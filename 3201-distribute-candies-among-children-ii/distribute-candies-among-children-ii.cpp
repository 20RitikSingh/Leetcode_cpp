class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res=0;
        for(int i=0;i<=min(n,limit);i++){
            if(n-i>2*limit) continue;
            int r=n-i;
            int k=min(r,limit)-max(0,r-limit)+1;
            // cout<<k<<endl;
            res+=max(0,k);
        }
        return res;
    }
};