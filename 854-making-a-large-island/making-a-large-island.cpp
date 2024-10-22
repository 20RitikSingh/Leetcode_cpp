class Solution {
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            // Combine the two integers' hashes
            return std::hash<T1>()(p.first) ^ (std::hash<T2>()(p.second) << 1);
        }
    };
    int dfs(vector<vector<int>>& grid,vector<vector<pair<int,int>>>  &v,int x,int y,int pi,int pj){
        int n=grid.size();
        if(x<0 || y<0 || x>=n || y>=n || !grid[x][y] || v[x][y].first>=0) return 0;
        v[x][y]={pi,pj};
        return 1+dfs(grid,v,x+1,y,pi,pj)+dfs(grid,v,x-1,y,pi,pj)+dfs(grid,v,x,y+1,pi,pj)+dfs(grid,v,x,y-1,pi,pj);
    }
    int mrg(vector<vector<int>>& grid,vector<vector<pair<int,int>>> &v,vector<vector<int>> &u,int x,int y){
        int k=1,n=grid.size();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        unordered_set<pair<int,int>,pair_hash> st={{-1,-1}};
        for(int i=0;i<4;i++){
            int x1=x+dx[i],y1=y+dy[i];
            if(x1>=0 && y1>=0 && x1<n && y1<n && !st.count(v[x1][y1])){ 
                k+=u[v[x1][y1].first][v[x1][y1].second];
                st.insert(v[x1][y1]);
            }
        }
        return k;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>(n,{-1,-1}));
        vector<vector<int>> u(n,vector<int>(n));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j].first<0) u[i][j]=dfs(grid,v,i,j,i,j);
                res=max(res,u[i][j]);
                // cout<<u[i][j]<<" ";
            }
            // cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]){ 
                    res=max(res,mrg(grid,v,u,i,j));
                    // cout<<i<<" "<<j<<" "<<mrg(grid,v,u,i,j)<<endl;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<u[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<v[i][j].first<<","<<v[i][j].second<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return res;
    }
};