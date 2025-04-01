class Solution {
    unordered_map<int,long long> dp;
    long long rec(vector<vector<int>> &ques,int curr){
        if(curr>=ques.size()) return 0;
        if(dp.find(curr)==dp.end()) dp[curr] =max(rec(ques,curr+1),ques[curr][0]+rec(ques,curr+ques[curr][1]+1));
        return dp[curr];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return rec(questions,0);
    }
};