class Solution {
    int check(vector<int>& candies, long long k,int mx){
        if(mx==0) return 1;
        for(int i:candies){
            k-=i/mx;
        }
        if(k>0) return 0;
        return 1;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low=0,high=*max_element(candies.begin(),candies.end());
        // for(int i=high;i>=0;i--) if(check(candies,k,i)) return i;
        while(low<high-1){
            int mid=low+(high-low)/2;
            if(check(candies,k,mid)) low=mid;
            else high=mid-1;
        }
        if(check(candies,k,high)) return high;
        return low;
    }
};