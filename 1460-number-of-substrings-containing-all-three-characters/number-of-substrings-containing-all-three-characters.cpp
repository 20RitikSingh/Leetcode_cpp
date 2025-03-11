class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0,n=s.size();
        vector<vector<int>> v(2,vector<int>(3,1e9));
        v[0][s[n-1]-'a']=n-1;
        for(int i=n-2;i>=0;i--){ 
            v[0][s[i]-'a']=i;
            res+=max(0,n-max(v[0][0],max(v[0][1],v[0][2])));
            v[1]=v[0];
        }
        return res;
    }
};