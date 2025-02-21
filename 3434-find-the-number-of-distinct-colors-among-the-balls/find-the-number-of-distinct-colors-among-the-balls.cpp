class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> c2f,b2c;
        vector<int> res;
        int n=1;
        c2f[0]=limit+1;
        for(auto q:queries){
            if(c2f[b2c[q[0]]]==1) n--;
            c2f[b2c[q[0]]]--;
            if(c2f[q[1]]==0) n++;
            b2c[q[0]]=q[1];
            c2f[q[1]]++;
            res.push_back(n-(bool)c2f[0]);
        }
        return res;
    }
};