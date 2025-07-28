class Solution {
    int dp[11][2][11];
    int rec(vector<int> &v,int idx,bool tight,int count){
        if(dp[idx][tight][count]!=-1) return dp[idx][tight][count];
        if(idx==v.size()) return tight?0:count;
        int res=0;
        for(int i=0;i<10;i++){
            res+=rec(v,idx+1,v[idx]<i?1:(v[idx]==i?tight:0),count+(i==1));
        }
        return dp[idx][tight][count]=res;
    }
public:
    int countDigitOne(int n) {
        if(!n) return 0;
        vector<int> v;
        while(n){
            v.push_back(n%10),n/=10;
        }
        memset(dp,-1,sizeof(dp));
        return rec(v,0,0,0);
    }
};