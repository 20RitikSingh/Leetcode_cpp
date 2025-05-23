unordered_map<int,int> dp;
class Solution {
public:
    int minDays(int n) {
        if(n<2) return n;
        if(dp.count(n)) return dp[n];
        int res=1e9;
        if(n%3==0) res=min(res,1+minDays(n/3));
        else res=min(res,n%3+1+minDays(n/3));
        if(n%2==0) res=min(res,1+minDays(n/2));
        else res=min(res,n%2+1+minDays(n/2));
        dp[n]=res;
        return res;
    }
};