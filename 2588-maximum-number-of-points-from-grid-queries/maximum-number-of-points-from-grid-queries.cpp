class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> cum(1e6+1);
        int m=grid.size(),n=grid[0].size();
        vector<bool> vis(n*m);
        set<pair<int,int>> set;
        set.insert({grid[0][0],0});
        int mx=grid[0][0];
        while(set.size()){
            auto it=set.begin();
            auto [k,v]=*it;
            // cout<<k<<" "<<v/n<<","<<v%n<<endl;
            set.erase(it);
            mx=max(mx,k);
            cum[mx]++;
            vis[v]=1;
            int i=v/n,j=v%n;
            if(i>0 && !vis[(i-1)*n+j]) set.insert({grid[i-1][j],(i-1)*n+j});
            if(j>0 && !vis[i*n+j-1]) set.insert({grid[i][j-1],i*n+j-1});
            if(i<m-1 && !vis[(i+1)*n+j]) set.insert({grid[i+1][j],(i+1)*n+j});
            if(j<n-1 && !vis[i*n+j+1]) set.insert({grid[i][j+1],i*n+j+1});
        }
        for(int i=1;i<=1e6;i++){
            cum[i]+=cum[i-1];
        }
        vector<int> res;
        for(int i:queries){
            res.push_back(cum[i-1]);
        }
        return res;
    }
};