class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        int prev=0,cur=1;
        vector<int> v(n);
        while(cur<n){
            if(s[prev]==s[cur]){
                prev++;
                v[cur]=prev;
                cur++;
                continue;
            }
            if(prev) prev=v[prev-1];
            else cur++;
        }
        return s.substr(0,v.back());
    }
};