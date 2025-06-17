unordered_map<long long,long long> dp[9];
class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long low=1,high=1e15;
        if(dp[x].count(k)) return dp[x][k];
        while (low < high) {
            long long mid = low + (high - low + 1) / 2,res=0;
            for(int i=x;i<60;i+=x) res+=(mid/(1LL<<i))*((1LL<<i)/2)+max(0LL,mid%(1LL<<i)-((1LL<<i)/2)+1);
            if (res <= k) low=mid;
            else high = mid - 1;
        }
        dp[x][k]=low;
        return low;
    }
};