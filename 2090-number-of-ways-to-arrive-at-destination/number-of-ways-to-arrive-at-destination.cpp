class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        int mod=1e9+7;
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        set<tuple<long long,int>> set;
        vector<long long> time(n,1e15),ways(n,0);
        time[0]=0;
        ways[0]=1;
        set.insert({0,0});
        while(set.size()){
            auto [t,from]=*set.begin();
            set.erase(set.begin());
            // cout<<t<<" "<<from<<" "<<ways[from]<<endl;
            if(from==n-1) return ways[n-1];
            for(auto [to,cst]:adj[from]){
                long long ncst=t+cst;
                if(ncst>time[to]) continue;
                if(ncst!=time[to]) ways[to]=0;
                ways[to]+=ways[from];
                ways[to]%=mod;
                time[to]=ncst;
                set.insert({ncst,to});
            }
        }
        return -1;
    }
};