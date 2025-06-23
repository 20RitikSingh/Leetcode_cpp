class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            int r=i,c=0;
            while(r<n && c<n){
                cout<<r<<","<<c<<" ";
                q.push(grid[r++][c++]);
            }
            cout<<endl;
            r=i,c=0;
            while(r<n && c<n){
                grid[r++][c++]=q.top();
                q.pop();
            }
        }
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=1;i<n;i++){
            int r=0,c=i;
            while(r<n && c<n){
                cout<<r<<","<<c<<" ";
                pq.push(grid[r++][c++]);
            }
            cout<<endl;
            r=0,c=i;
            while(r<n && c<n){
                grid[r++][c++]=pq.top();
                pq.pop();
            }
        }
        return grid;
    }
};