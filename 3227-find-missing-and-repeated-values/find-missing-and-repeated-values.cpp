class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int a=0,n=grid.size(),m=grid[0].size();
        int res=n*n*(n*n+1)/2;
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res-=grid[i][j];
                if(set.count(grid[i][j])) a=grid[i][j];
                else set.insert(grid[i][j]);
            }
        }
        return {a,res+a};
    }
};