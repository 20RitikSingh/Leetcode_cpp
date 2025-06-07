class Solution {
    int depth(int x){
        return logb(x);
    }
    int lca(int x,int y){
        // cout<<"lca: "<<x<<" "<<y<<endl;
        bitset<32> p(x),q(y);
        // cout<<"x: "<<p<<endl;
        // cout<<"y: "<<q<<endl;
        int i=31,j=31;
        while(!p[i]) i--;
        while(!q[j]) j--;
        // cout<<i<<" "<<j<<endl;
        int c=i+j+2;
        // cout<<c<<endl;
        while(i>=0 && j>=0 && p[i--]==q[j--]){
            c-=2;
        }
        // cout<<c<<endl;
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