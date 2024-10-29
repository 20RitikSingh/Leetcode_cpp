class Solution {
    int rec(vector<vector<int>>& matrix,vector<vector<bool>> &vis,int r,int c){
        int res=0,m=matrix.size(),n=matrix[0].size();
        int sz=0;
        while(sz<min(m-r,n-c)){
            for(int i=r;i<=r+sz;i++){
                if(!matrix[i][c+sz]) return sz;
            }
            for(int j=c;j<=c+sz;j++){
                if(!matrix[r+sz][j]) return sz;
            }
            sz++;
        }
        return sz;

    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res=0,m=matrix.size(),n=matrix[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res+=rec(matrix,vis,i,j);
                // cout<<rec(matrix,vis,i,j)<<endl;
            }
        }
        return res;
    }
};