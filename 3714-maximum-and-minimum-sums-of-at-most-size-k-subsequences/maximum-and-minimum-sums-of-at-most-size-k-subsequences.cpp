class Solution {
    const int MOD = 1e9+7;

public:
    int minMaxSums(vector<int>& nums, int k) {
        long long res=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ncr(nums.size() + 1, vector<int> (k + 1,0));
        
        ncr[0][0] = 1;
        for (int n = 1; n <= nums.size(); n++) {
            ncr[n][0] = 1;
            for (int r = 1; r <= k; r++) 
                ncr[n][r] = (ncr[n - 1][r - 1] + ncr[n - 1][r]) % MOD;
        } 
        for(int i=0;i<n;i++){
            int low=i,high=n-i-1;
            for(int j=0;j<=min(k-1,low);j++){
                res+=1LL*ncr[low][j]*nums[i];
                res%=MOD;
            }
            for(int j=0;j<=min(high,k-1);j++){
                res+=1LL*ncr[high][j]*nums[i];
                res%=MOD;
            }
        }
        return res;
    }
};