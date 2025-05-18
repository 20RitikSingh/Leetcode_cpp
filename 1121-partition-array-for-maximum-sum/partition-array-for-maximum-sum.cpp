class Solution {
    int dp[501];
    int rec(vector<int> &arr,int k,int idx){
        if(idx>=arr.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mx=arr[idx];
        for(int i=idx;i<arr.size() && i<idx+k;i++){
            mx=max(arr[i],mx);
            dp[idx]=max(dp[idx],mx*(i-idx+1)+rec(arr,k,i+1));
        }
        return dp[idx];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return rec(arr,k,0);
    }
};