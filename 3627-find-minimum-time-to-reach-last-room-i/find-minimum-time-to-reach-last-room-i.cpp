class cmp{
    public:
    bool operator()(vector<int> &a, vector<int> &b){
        return a[0]>b[0];
    }
};
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<vector<int>,vector<vector<int>>,cmp> q;
        q.push({0,0,0});
        vector<vector<int>> cost(moveTime.size(),vector<int>(moveTime[0].size(),2e9));
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(q.size()){
            auto curr=q.top();
            q.pop();
            for(int i=0;i<4;i++){
                int x=curr[1]+dx[i];
                int y=curr[2]+dy[i];
                if(x<0 || y<0 || x>=moveTime.size() || y>=moveTime[0].size() || cost[x][y]<2e9) continue;
                int newCost=max(curr[0],moveTime[x][y])+1;
                if(x==moveTime.size()-1 && y==moveTime[0].size()-1) return newCost;
                if(newCost<cost[x][y]){
                    q.push({newCost,x,y});
                    cost[x][y]=newCost;
                }
            }
        }
        return -1;
    }
};