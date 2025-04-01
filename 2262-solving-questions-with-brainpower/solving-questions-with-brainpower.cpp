class Solution {
    long long dp[100001];
    long long rec(vector<vector<int>> &ques,int curr){
        if(curr>=ques.size()) return 0;
        if(!dp[curr]) dp[curr] =max(rec(ques,curr+1),ques[curr][0]+rec(ques,curr+ques[curr][1]+1));
        return dp[curr];
    }
public:
    long long mostPoints(vector<vector<int>>& ques) {
        return rec(ques,0);
    }
};