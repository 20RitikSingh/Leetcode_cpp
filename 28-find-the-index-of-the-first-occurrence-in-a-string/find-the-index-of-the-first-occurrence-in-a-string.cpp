class Solution {
    int dfs(string &s,string &p,int i,int j){
        if(j==p.size()) return i-p.size();
        if(i==s.size() || s[i]!=p[j]) return -1; 
        return dfs(s,p,i+1,j+1);
    }
public:
    int strStr(string s, string p) {
        for(auto &ch:p) ch-='a';
        for(auto &ch:s) ch-='a';
        for(int i=0;i<s.size();i++) if(dfs(s,p,i,0)>=0) return i;
        return -1;
        
    }
};