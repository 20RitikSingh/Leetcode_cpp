class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        vector<int> v(1e5+1);
        int res=0;
        for(int i:nums) v[i]++;
        for(int i:nums){
            if(!v[i]) continue;
            int x=1,k=i;
            v[i]--;
            while(1){
                long long t=k;
                t*=k;
                v[k]--;
                if(t>1e5 || !v[t]) break;
                x++;
                k=t;
            }
            k=i;
            while(1){
                int t=sqrt(k);
                v[k]--;
                if(t*t<k || !v[t]) break;
                x++;
                k=t;
            }
            res=max(res,x);
        }
        return res>1?res:-1;
    }
};