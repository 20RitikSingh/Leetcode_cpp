class Solution {
    vector<vector<string>> res;
    void rec(vector<string> &v,int idx){
        int n=v.size();
        if(idx==n) res.push_back(v);
        else for(int i=0;i<n;i++){
            for(int j=0;j<=idx;j++) if(v[j][i]=='Q' || (i>=j && v[idx-j][i-j]=='Q') || (i+j<n && v[idx-j][i+j]=='Q')) goto skip;
            v[idx][i]='Q';
            rec(v,idx+1);
            v[idx][i]='.';
            skip:;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n,string(n,'.'));
        rec(v,0);
        return res;
    }
};