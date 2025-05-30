class Solution {
public:
    int strStr(string s, string p) {
        for(auto &ch:p) ch-='a';
        for(auto &ch:s) ch-='a';
        queue<int> q;
        for(int i=0;i<s.size();i++) q.push(i);

        for(int i=0;i<p.size();i++){
            int sz=q.size();
            for(int j=0;j<sz;j++){
                int x=q.front();
                q.pop();
                if(x<s.size() && s[x]==p[i] && s.size()-x>=p.size()-i) q.push(x+1);
            }
            if(q.empty()) return -1;
        }
        return q.front()-p.size();
    }
};