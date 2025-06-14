class Solution {
    int pow2(int x){
        int c=0;
        while(x%2==0){
            x/=2;
            c++;
        }
        return c;
    }
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n;i++){
            vector<int> v(32);
            int g=nums[i];
            for(int j=i;j<n;j++){
                g=gcd(g,nums[j]);
                long long ans=1LL*g*(j-i+1);
                v[pow2(nums[j])]++;
                for(int p=0;p<32;p++){
                    if(v[p]){
                        if(k>=v[p]) ans*=2;
                        break;
                    }
                }
                res=max(res,ans);
            }
        }
        return res;
    }
};