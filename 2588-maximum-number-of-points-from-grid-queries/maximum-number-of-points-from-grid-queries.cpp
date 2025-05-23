class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size(),n=grid[0].size();
        priority_queue<tuple<int,int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n));
        vector<int> res(queries.size());
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int k=0;

        int mx_query=*max_element(queries.begin(),queries.end());
        vector<int> v(mx_query+1);

        q.push({0-grid[0][0],0,0});
        vis[0][0]=1;

        while(q.size()){
            auto [val,r,c]=q.top();
            q.pop();
            k=max(k,0-val+1);
            if(k>mx_query) break;
            v[k]++;

            for(int i=0;i<4;i++){
                int x=r+dx[i],y=c+dy[i];
                if(x<0 || y<0 || x>=m || y>=n || vis[x][y]) continue;
                q.push({0-grid[x][y],x,y});
                vis[x][y]=1;
            }
        }
        
        for(int i=1;i<=mx_query;i++){
            v[i]+=v[i-1];
        }
        
        for(int i=0;i<queries.size();i++){
            res[i]=v[queries[i]];
        }

        return res;
    }
};