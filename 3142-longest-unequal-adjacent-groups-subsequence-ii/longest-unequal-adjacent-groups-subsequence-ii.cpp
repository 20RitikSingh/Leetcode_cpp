class Solution {
    int hammingDist(string s,string t){
        int c=0;
        for(int i=0;i<s.size();i++){
            c+=s[i]!=t[i];
        }
        return c;
    }
    vector<int> nxt;
    int dp[1001];
    int rec(vector<string>&words,vector<int> &groups,int idx){
        if(dp[idx]>=0) return dp[idx];
        int res=0;
        for(int i=idx+1;i<words.size();i++){
            if(words[i].size()==words[idx].size() && groups[i]!=groups[idx] && hammingDist(words[idx],words[i])==1){
                int x=rec(words,groups,i);
                if(x>res){
                    res=x;
                    nxt[idx]=i;
                }
            }
        }
        dp[idx]=res+1;
        return res+1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int mx=-1,sel=-1;
        memset(dp,-1,sizeof(dp));
        nxt=vector<int>(words.size(),-1);
        for(int i=0;i<words.size();i++){
            int x=rec(words,groups,i);
            // cout<<i<<" "<<x<<endl;
            if(x>mx) mx=x,sel=i;
        }
        while(sel!=-1){
            res.push_back(words[sel]);
            sel=nxt[sel];
        }
        return res;
    }
};