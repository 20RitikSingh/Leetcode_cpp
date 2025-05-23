char dp[2000000000];
class Solution {
public:
    int minDays(int n) {
        if(n<2) return n;
        if(!dp[n]) dp[n]=1+min(n%3+minDays(n/3),n%2+minDays(n/2));
        return dp[n];
    }
};