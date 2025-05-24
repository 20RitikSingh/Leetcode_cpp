class Solution {
    vector<vector<int>> adj;
    int dp[50000];
    int rec(vector<int> &time,int curr){
        if(dp[curr]) return dp[curr];
        int res=0;
        for(int i:adj[curr]){
            res=max(res,rec(time,i));
        }
        dp[curr]=res+time[curr];
        return res+time[curr];
    }
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        adj=vector<vector<int>>(n);
        for(auto r:relations) adj[r[1]-1].push_back(r[0]-1);
        int res=0;
        for(int i=0;i<n;i++) res=max(res,rec(time,i));
        return res;
    }
};