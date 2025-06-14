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
            int g=nums[i],c=0,mi=32;
            for(int j=i;j<n;j++){
                g=gcd(g,nums[j]);
                int x=pow2(nums[j]);
                if(x<mi){
                    c=1;
                    mi=x;
                }else if(x==mi) c++;
                long long ans=1LL*g*(j-i+1);
                if(k>=c) ans*=2;
                res=max(res,ans);
            }
        }
        return res;
    }
};