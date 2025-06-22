class Solution {
    double dp[1<<12][6][2];
    double calcmax(vector<int> &time,int msk,double stage){
        int mx=-1e9,n=time.size();
        for(int i=0;i<n;i++) if(msk&(1<<i)) mx=max(mx,time[i]);
        return stage*mx;
    }
public:
    double minTime(int n, int k, int m, vector<int>& time, vector<double>& mul) {
        if(k==1 && n!=1) return -1;
        for(int i=0;i<(1<<n);i++) for(int j=0;j<m;j++) dp[i][j][0]=dp[i][j][1]=1e9;
        set<tuple<double,int,int,bool>> set;
        set.insert({0,0,0,0});
        while(set.size()){
            auto [cost,msk,stage,f]=*set.begin();
            set.erase(set.begin());
            int t=__builtin_popcount(msk);
            if(t==n) return cost;
            if(dp[msk][stage][f]<cost) continue;
            dp[msk][stage][f]=cost;
            if(f){
                for(int i=0;i<n;i++){
                    if(msk&(1<<i)){
                        double x=mul[stage]*time[i];
                        int newstage=(stage+int(floor(x))%m)%m;
                        set.insert({x+cost,msk^(1<<i),newstage,0});
                    }
                }
                continue;
            }
            for (int sup = msk; sup < (1 << n); sup = (sup + 1) | msk) {
                if (sup == msk || __builtin_popcount(sup)-t > k) continue;                   
                double x = calcmax(time, sup^msk, mul[stage]);
                int newstage = (stage + int(floor(x)) % m) % m;
                set.insert({x+cost,sup,newstage,1});
            }
        }
        return 0;
    }
};