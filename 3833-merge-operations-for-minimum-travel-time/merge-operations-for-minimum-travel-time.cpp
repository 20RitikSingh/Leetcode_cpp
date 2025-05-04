class Solution {
    int dp[11][51][101];
    int rec(vector<int> &d,vector<int> &t,int k,int idx,int prev){
        if(idx>=d.size()) return k?1e9:0;
        if(dp[k][idx][prev]) return dp[k][idx][prev];
        int c=d[idx]*(t[idx]+prev),s=0,p=0;
        dp[k][idx][prev]=rec(d,t,k,idx+1,0)+c;
        for(int i=1;i+idx<d.size() && k-i>=0;i++){
            p+=d[i+idx]*(t[idx]+prev);
            s+=t[i+idx];
            dp[k][idx][prev]=min(dp[k][idx][prev],rec(d,t,k-i,idx+i+1,s)+p+c);
        }
        return dp[k][idx][prev];
    }
public: 
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        vector<int> d,t=time;
        for(int i=1;i<n;i++) d.push_back(position[i]-position[i-1]);
        return rec(d,t,k,0,0);
    }
};