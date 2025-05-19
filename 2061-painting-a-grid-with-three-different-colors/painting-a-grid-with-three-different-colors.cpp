class Solution {
    int dp[5][1000][4][1025],mod=1e9+7;
    int mskpush(int msk,int n,int pos){
        int back=(1<<(pos))-1;
        back=msk&back;
        msk>>=pos+2;
        msk<<=2;
        msk+=n;
        msk<<=pos;
        msk+=back;
        return msk;
    }
    int rec(int m, int n,int r,int c,int back,int up){
        if(c>=n) return 1;
        if(r>=m) return rec(m,n,0,c+1,3,up);

        int x=(up>>(2*r))&3;

        if(dp[r][c][back][up]!=0) return dp[r][c][back][up];
        
        long long res=0;
        for(int i=0;i<3;i++){
            if(i==x || i==back) continue;
            res+=rec(m,n,r+1,c,i,mskpush(up,i,2*r));
            res%=mod;
        }
        dp[r][c][back][up]=res;
        return res;
    }
public:
    int colorTheGrid(int m, int n) {
        int msk=(1<<(2*m))-1;
        // memset(dp,-1,sizeof(dp));
        return rec(m,n,0,0,3,msk);
    }
};