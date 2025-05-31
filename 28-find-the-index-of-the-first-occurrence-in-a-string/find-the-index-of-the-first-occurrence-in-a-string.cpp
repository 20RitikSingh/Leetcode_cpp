class Solution {
public:
    int strStr(string s, string p) {
        if(s.size()<p.size()) return -1;
        vector<int> pi(p.size());
        int prev=0,cur=1;
        while(cur<p.size()){
            if(p[prev]==p[cur]){
                prev++;
                pi[cur]=prev;
                cur++;
                continue;
            }
            if(prev) prev=pi[prev-1];
            else cur++;
        }
        // for(int i:pi) cout<<i<<" ";
        cur=0;
        int i=0;
        while(i<=s.size()){
            // cout<<i<<" "<<cur<<endl;
            if(cur==p.size()) return i-p.size();
            if(s[i]==p[cur]){
                cur++;
                i++;
                continue;
            }
            if(cur) cur=pi[cur-1];
            else i++;
        }
        return -1;
    }
};