class Solution {
    int lca(int x,int y){
        bitset<32> p(x),q(y);
        int i=31,j=31;
        while(!p[i]) i--;
        while(!q[j]) j--;
        int c=i+j+2;
        while(i>=0 && j>=0 && p[i--]==q[j--]){
            c-=2;
        }
        return c+1;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto q:queries){
            res.push_back(lca(q[0],q[1]));
        }
        return res;
    }
};