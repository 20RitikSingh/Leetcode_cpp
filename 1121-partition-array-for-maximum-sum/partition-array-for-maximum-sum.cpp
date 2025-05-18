class Solution {
    int dp[501];
    int rec(vector<int> &arr,int k,int idx){
        int n=arr.size(),res=0;
        if(idx>=n) return 0;
        if(dp[idx]) return dp[idx];
        int mx=arr[idx];
        for(int i=idx;i<n && i<idx+k;i++){
            mx=max(arr[i],mx);
            res=max(res,mx*(i-idx+1)+rec(arr,k,i+1));
        }
        dp[idx]=res;
        return res;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return rec(arr,k,0);
    }
};