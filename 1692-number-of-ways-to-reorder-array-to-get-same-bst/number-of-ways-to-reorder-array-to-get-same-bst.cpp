
class Solution {
int mod=1e9+7;
unordered_map<int, unordered_map<int, int>> dp;
int table(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (dp[n][k]) return dp[n][k];
    return dp[n][k] = (table(n - 1, k - 1) + table(n - 1, k)) % mod;
}
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        queue<vector<int>> q;
        q.push(nums);
        int res=1;
        while(q.size()){
            auto v=q.front();
            q.pop();
            vector<int> x,y;
            for(int i=1;i<v.size();i++){
                if(v[i]<v[0]) x.push_back(v[i]);
                else y.push_back(v[i]);
            }
            if(x.size()) q.push(x);
            if(y.size()) q.push(y);
            res=(1LL*res*table(x.size()+y.size(),x.size()))%mod;
        }
        return res-1;
    }
};