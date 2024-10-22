class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int t=0;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        while(!pq.empty()){
            auto [h,inner]=pq.top();
            auto [x,y]=inner;
            t=max(t,h);
            if(x==n-1 && y==n-1) return t;
            pq.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=n || vis[nx][ny]) continue;
                pq.push({grid[nx][ny],{nx,ny}});
                vis[nx][ny]=1;
            }
        }
        return t;
    }
};