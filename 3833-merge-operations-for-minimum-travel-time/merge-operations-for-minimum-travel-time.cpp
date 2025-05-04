class Solution {
    int dp[11][51][101];
    int rec(vector<int> &d,vector<int> &t,int k,int idx,int prev){
        if(idx>=d.size()) return k?1e9:0;
        if(dp[k][idx][prev]) return dp[k][idx][prev];
        int c=d[idx]*(t[idx]+prev);
        int mi=rec(d,t,k,idx+1,0)+c;
        int s=0,p=0;
        for(int i=1;i+idx<d.size() && k-i>=0;i++){
            p+=d[i+idx]*(t[idx]+prev);
            s+=t[i+idx];
            // cout<<d[i+idx]<<" ";
            mi=min(mi,rec(d,t,k-i,idx+i+1,s)+p+c);
            // cout<<endl;
        }
        dp[k][idx][prev]=mi;
        return mi;
    }
public: 
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> d,t;
        for(int i=1;i<n;i++){
            d.push_back(position[i]-position[i-1]);
        }
        t=time;
        t.pop_back();
        // for(int i:d) cout<<i<<" ";
        // cout<<endl;
        // for(int i:t) cout<<i<<" ";
        // cout<<endl;
        return rec(d,t,k,0,0);
    }
};