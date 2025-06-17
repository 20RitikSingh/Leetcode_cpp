class Solution {
    long long calc(long long n,long long k){
        long long rem=n%k-(k/2)+1;
        // cout<<n<<" "<<k<<" "<<rem<<" "<<(n/k)*(k/2)+max(0LL,rem)<<endl;
        return (n/k)*(k/2)+max(0LL,rem);
    }
    long long check(long long n,int x){
        long long res=0;
        for(int i=x;i<60;i+=x){
            res+=calc(n,1LL<<i);
        // cout<<res<<endl;
        }
        return res;
    }
public:
    long long findMaximumNumber(long long k, int x) {
        long long low=1,high=1e15;
        while (low < high) {
            long long mid = low + (high - low + 1) / 2; 
            if (check(mid, x) <= k) low=mid;
            else high = mid - 1;
        }
        return low;
    }
};