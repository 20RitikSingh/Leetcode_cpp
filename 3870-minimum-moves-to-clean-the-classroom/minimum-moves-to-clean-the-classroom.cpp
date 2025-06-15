class Solution {
public:
    int minMoves(vector<string>& room, int energy) {
        set<tuple<int,int,int,int,long long>> set;
        unordered_map<int,int> mp;
        int n=room.size(),m=room[0].size(),p=0,r=0,k=0;
        long long tmp=0;
        for(int i=0;i<n;i++) 
            for(int j=0;j<m;j++){
                if(room[i][j]=='S') p=i,r=j;
                if(room[i][j]=='L'){ 
                    mp[(i*m+j)]=k++;
                    tmp|=1LL<<mp[i*m+j];
                }
            } 
        int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
        set.insert({0,energy,p,r,tmp});
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(1<<k,-1)));
        while(set.size()){
            auto [cst,e,i,j,state]=*set.begin();
            set.erase(set.begin());
            if(dp[i][j][state]>=e) continue;
            dp[i][j][state]=e;
            if(mp.count((i*m+j)) && state&(1LL<<mp[(i*m+j)])) state^=(1LL<<mp[(i*m+j)]);
            if(state==0) return cst;
            if(room[i][j]=='R') e=energy;
            if(!e) continue;    
            for(int t=0;t<4;t++){
                int x=dx[t]+i,y=dy[t]+j;
                if(x<0 || y<0 || x>=n || y>=m || room[x][y]=='X') continue;
                set.insert({cst+1,e-1,x,y,state});
            }
        }
        return -1;
    }
};