class Solution {
public:
    int minMoves(vector<string>& grid, int energyMax) {
        int m = grid.size(), n = grid[0].size();
        int litterCount = 0;
        map<pair<int,int>, int> litterIndex;
        queue<tuple<int,int,int,int,int>> q; // x, y, energy, mask, steps
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(n, 
            vector<vector<bool>>(energyMax + 1, 
            vector<bool>(1 << 10, false))));

        // Find starting position and litter
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='S') {
                    q.push({i,j,energyMax,0,0});
                    visited[i][j][energyMax][0]=true;
                }
                if(grid[i][j]=='L'){
                    litterIndex[{i,j}] = litterCount++;
                }
            }
        }

        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto [x,y,energy,mask,steps] = q.front(); q.pop();

            if(mask == (1<<litterCount)-1) return steps;

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[nx][ny] == 'X') continue;

                // Prevent illegal move if energy is 0 and not on reset
                if (energy == 0 && grid[x][y] != 'R') continue;

                int newEnergy = energy - 1;
                if (grid[nx][ny] == 'R') newEnergy = energyMax;

                int newMask = mask;
                if (grid[nx][ny] == 'L') {
                    int idx = litterIndex[{nx, ny}];
                    newMask |= (1 << idx);
                }

                if (!visited[nx][ny][newEnergy][newMask]) {
                    visited[nx][ny][newEnergy][newMask] = true;
                    q.push({nx, ny, newEnergy, newMask, steps + 1});
                }
            }

        }

        return -1;
    }
};
