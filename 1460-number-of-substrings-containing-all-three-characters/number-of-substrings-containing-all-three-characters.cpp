class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0,n=s.size();
        vector<vector<int>> v(n,vector<int>(3,1e9));
        for(int i=n-1;i>=0;i--){
            if(i<n-1) v[i]=v[i+1];
            v[i][s[i]-'a']=i;
        }
        for (int i = 0; i < n; i++) {
            res+=max(0,n-max(v[i][0],max(v[i][1],v[i][2])));
        }
        return res;
    }
};