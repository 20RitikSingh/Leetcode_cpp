class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m == 1 && n == 1) return 1;
        else if(grid[0][0] == 0) return -1;
        bool canReach = false;
        for(int i = 0; i < m - 1; i++)
            if(i + grid[i][n - 1] >= m - 1){
                canReach = true;
                break;
            }
        if(!canReach){
            for(int i = 0; i < n - 1; i++)
                if(i + grid[m - 1][i] >= n - 1){
                    canReach = true;
                    break;
                }
            if(!canReach) return -1;
        }
        queue<pair<int,int>> q;
        vector<set<int>> row(m), col(n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                row[i].insert(j);
                col[j].insert(i);
            }

        q.push({0,0});
        row[0].erase(0);
        col[0].erase(0);
        int cst=1;
        while(q.size() && cst<1e5){
            int sz=q.size();
            cst++;
            for(int i=0;i<sz;i++){
                auto [r,c]=q.front();
                q.pop();
                auto it=col[c].upper_bound(r);
                while(it!=col[c].end() && *it<=r+grid[r][c]){
                    if(*it==m-1 && c==n-1) return cst;
                    q.push({*it,c});
                    row[*it].erase(c); 
                    it=col[c].erase(it);
                }
                it=row[r].upper_bound(c);
                while(it!=row[r].end() && *it<=c+grid[r][c]){
                    if(r==m-1 && *it==n-1) return cst;
                    q.push({r,*it});
                    col[*it].erase(r);
                    it=row[r].erase(it);
                }
            }
        }
        return -1;
    }
};
