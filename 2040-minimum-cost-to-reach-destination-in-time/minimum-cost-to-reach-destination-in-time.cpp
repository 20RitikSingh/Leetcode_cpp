class cmp{
    public:
    bool operator()(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[2]>b[2];
        return a[1]>b[1];
    }
};
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        vector<vector<pair<int,int>>> adj(n);
        for(auto e:edges){
            // mat[e[0]][e[1]]=min(mat[e[0]][e[1]],e[2]);
            // mat[e[1]][e[0]]=min(mat[e[1]][e[0]],e[2]);
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int t=min(mat[i][j],mat[j][i]);
        //         if(mat[i][j]<1e9){
        //             adj[i].push_back({j,t});
        //             adj[j].push_back({i,t});
        //         }
        //     }
        // }
        priority_queue<vector<int>,vector<vector<int>>,cmp> q;
        vector<int> cost(n,1e9),time(n,1e9);
        q.push({0,passingFees[0],0});
        while(q.size()){
            auto curr=q.top();
            q.pop();
            for(auto [i,t]:adj[curr[0]]){
                int newtime=t+curr[2];
                if(newtime>maxTime) continue;
                int newcost=curr[1]+passingFees[i];
                if(cost[i]<=newcost && time[i]<=newtime) continue;
                q.push({i,newcost,newtime});
                cost[i]=newcost;
                time[i]=newtime;
                if(i==n-1) return newcost;
            }
        }
        return -1;
    }
};