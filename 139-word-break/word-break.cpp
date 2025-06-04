class Solution {
    unordered_map<int,int> dp;
    bool rec(string &s,unordered_set<string> &set,int idx){
        int n=s.size();
        if(idx==n) return 1;
        if(dp.count(idx)) return dp[idx];
        for(int i=1;i<=n-idx;i++){
            string t=s.substr(idx,i);
            if(set.count(t)){
                if(rec(s,set,idx+i)) {dp[idx]=1;return 1;}
            }
        }
        dp[idx]=0;
        return 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        return rec(s,set,0);
    }
};