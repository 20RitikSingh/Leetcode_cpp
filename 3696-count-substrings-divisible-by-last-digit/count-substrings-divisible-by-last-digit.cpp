#define ll long long 
class Solution {
public:
    long long countSubstrings(string s) {
        for(char &i:s) i-='0';
        vector<vector<vector<ll>>> dp(2,vector<vector<ll>>(10,vector<ll>(10,0)));
        ll ans=0;
        for(int idx=0;idx<s.size();idx++){
            for(int d=1;d<10;d++){
                for(int r=0;r<10;r++){

                    if(idx==0){ 
                        dp[1][d][r]= (s[0]%d)==r;
                        continue;
                    }

                    dp[1][d][r]=(s[idx]%d)==r;

                    if((10%d)==0){
                        if(r!=(s[idx]%d)){
                            dp[1][d][r]=0;
                            continue;
                        }
                        for(int i=0;i<d;i++){
                            dp[1][d][r]+=dp[0][d][i];
                        }
                    }else{
                        for(int i=0;(i*d+r-(s[idx]%d))/(10%d)<d;i++){
                            if((i*d+r-(s[idx]%d))>=0 && (i*d+r-(s[idx]%d))%(10%d)==0) dp[1][d][r]+=dp[0][d][(i*d+r-(s[idx]%d))/(10%d)];
                        }
                    }
                }
            }
            ans+=dp[1][s[idx]][0];
            dp[0]=dp[1];
        }
        return ans;
    }
};