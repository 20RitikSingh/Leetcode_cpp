class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        priority_queue<int> q;
        int n=grid.size()*grid[0].size()/2;
        for(auto &i:grid) for(auto j:i) if(q.size()<=n) q.push(j); else if(q.top()>j){ q.pop(); q.push(j);}
        int ans=0,c=q.top();
        for(auto &i:grid)for(int j:i){
            if(abs(c-j)%x) return -1;
            ans+=abs(c-j)/x;        
        }
        return ans;
    }
};