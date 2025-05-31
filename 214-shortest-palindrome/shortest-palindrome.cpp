class Solution {
    int longestPrefixPalindrome(string s){
        string t=s;
        reverse(t.begin(),t.end());
        s=s+"#"+t;
        int n=s.size();
        vector<int> v(n);
        int prev=0,cur=1;
        while(cur<n){
            if(s[cur]==s[prev]){
                prev++;
                v[cur]=prev;
                cur++;
                continue;
            }
            if(prev) prev=v[prev-1];
            else cur++;
        }
        return v.back();
    }
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        int x=longestPrefixPalindrome(s);
        string tmp=s.substr(x,n-x);
        reverse(tmp.begin(),tmp.end());
        return tmp+s;
    }
};