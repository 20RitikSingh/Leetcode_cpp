class Solution {
    int row[9][10],col[9][10],block[9][10];
    int rec(vector<vector<char>>& board,int r,int c){
        // cout<<r<<" "<<c<<endl;
        if(c==9) return rec(board,r+1,0);
        if(r==9) return 1;
        if(board[r][c]!='.') return rec(board,r,c+1);
        for(int i=1;i<10;i++){
            int b=(r/3)*3+c/3;
            // cout<<r<<" "<<c<<" "<<b<<endl;
            if(row[r][i] || col[c][i] || block[b][i]) continue;
            board[r][c]='0'+i;
            row[r][i]=1;
            col[c][i]=1;
            block[b][i]=1;
            if(rec(board,r,c+1)) return 1;
            row[r][i]=0;
            col[c][i]=0;
            block[b][i]=0;
            board[r][c]='.';
        }
        return 0;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                row[i][board[i][j]-'0']=1;
                col[j][board[i][j]-'0']=1;
                block[(i/3)*3+j/3][board[i][j]-'0']=1;
            }
        }
        rec(board,0,0);
    }
};