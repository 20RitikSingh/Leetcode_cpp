class Solution {
    vector<vector<int>> adj;
    vector<int> fur,p;
    vector<vector<int>> dp2;
    int rec(vector<vector<int>> &v,int b,int idx){
        if(b<0) return -1e9;
        if(idx==v.size()) return 0;
        if(dp2[b][idx]!=-1) return dp2[b][idx];
        int res=-1e9;
        for(int i=0;i<=b;i++){
            res=max(res,rec(v,b-i,idx+1)+v[idx][i]);
        }
        dp2[b][idx]=res;
        return res;
    }
    vector<int> knapsack(vector<vector<int>> &v,int b){
        dp2=vector<vector<int>>(b+1,vector<int>(v.size(),-1));
        vector<int> res(b+1);
        for(int i=0;i<=b;i++){
            res[i]=rec(v,i,0);
        }
        return res;
    }
    vector<int> dp[160][2];
    vector<int> rec(int cur,int f,int b){
        if(dp[cur][f].size()) return dp[cur][f];
        int profit=fur[cur];
        if(f) profit-=p[cur]/2;
        else profit-=p[cur];
        //buy
        vector<vector<int>> v,u;
        for(int i:adj[cur]){
            v.push_back(rec(i,1,b));
        }
        //not buy
        for(int i:adj[cur]){
            u.push_back(rec(i,0,b));
        }
        vector<int> tmp1=knapsack(v,b);
        vector<int> tmp2=knapsack(u,b);
        for(int i=fur[cur]-profit;i<=b;i++){
            tmp2[i]=max(tmp2[i],tmp1[i-(fur[cur]-profit)]+profit);
        }
        dp[cur][f]=tmp2;
        return tmp2;
    }
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& edges, int budget) {
        fur=future;
        p=present;
        adj.resize(n);
        for(auto e:edges){
            adj[e[0]-1].push_back(e[1]-1);
        }
        return rec(0,0,budget)[budget];
    }
};