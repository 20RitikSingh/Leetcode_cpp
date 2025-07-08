class Solution {
    vector<vector<int>> dp;
    int rec(vector<vector<int>> &events,int idx,int k){
        // cout<<idx<<" ";
        int n=events.size();
        if(idx==n || !k) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        int res=max(events[idx][2],rec(events,idx+1,k));
        for(int i=idx+1;i<n;i++){
            if(events[i][0]>events[idx][1]){
                res=max(res,rec(events,i,k-1)+events[idx][2]);
                break;
            }
        }
        // cout<<endl;
        return dp[idx][k]=res;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        // for(auto &i:events) swap(i[0],i[1]);
        sort(events.begin(),events.end());
        // for(auto i:events) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        dp.resize(events.size(),vector<int>(k+1,-1));
        return rec(events,0,k);
    }
};