class Solution {
public:
    int minChanges(string s) {
        int k=0;
        for(int i=0;i<s.size();i+=2) k+=(s[i]!=s[i+1]);
        return k;
    }
};