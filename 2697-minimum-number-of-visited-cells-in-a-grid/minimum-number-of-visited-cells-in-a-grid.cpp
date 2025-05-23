class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // if(m==1 && n==1) return 1;
        queue<tuple<int,int,int>> q;
        vector<set<int>> row(m), col(n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                row[i].insert(j);
                col[j].insert(i);
            }

        q.push({0,0,1});
        row[0].erase(0);
        col[0].erase(0);
        while(q.size()){
            auto [r,c,cst]=q.front();
            q.pop();

            if(r==m-1 && c==n-1) return cst;

            auto it=col[c].upper_bound(r);
            while(it!=col[c].end() && *it<=r+grid[r][c]){
                // if(*it==m-1 && c==n-1) return cst+1;
                q.push({*it,c,cst+1});
                row[*it].erase(c); 
                it=col[c].erase(it);
            }
            
            it=row[r].upper_bound(c);
            while(it!=row[r].end() && *it<=c+grid[r][c]){
                // if(r==m-1 && *it==n-1) return cst+1;
                q.push({r,*it,cst+1});
                col[*it].erase(r);
                it=row[r].erase(it);
            }
        }
        return -1;
    }
};
