class Solution {
public:
    int strStr(string s, string p) {
        if(p=="") return 0;
        s=p+"#"+s;
        int n=s.size();
        vector<int> v(n);
        int prev=0,cur=1;
        while(cur<n){
            if(s[cur]==s[prev]){
                prev++;
                v[cur]=prev;
                if(v[cur]==p.size()) return cur-2*p.size();
                cur++;
                continue;
            }
            if(prev) prev=v[prev-1];
            else cur++;
        }
        return -1;
    }
};