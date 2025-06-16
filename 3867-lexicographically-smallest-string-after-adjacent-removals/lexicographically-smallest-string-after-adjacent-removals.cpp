class Solution {
    int dp[250][250];
    bool check(string &s,int low,int high){
        if(high<low) return 1;
        if(dp[low][high]) return dp[low][high]-1;
        if(abs(s[low]-s[high])==1 || abs(s[low]-s[high])==25) dp[low][high]|=check(s,low+1,high-1);
        for(int i=low+1;i<high-1 && !dp[low][high];i+=2) 
            dp[low][high]|=check(s,low,i)&check(s,i+1,high);
        return dp[low][high]++;
    }
    string dp2[250];
    string rec2(string &s,int i){
        int n=s.size();
        if(check(s,i,n-1)) return "";
        if(dp2[i]!="") return dp2[i];
        dp2[i]=s.substr(i,1)+rec2(s,i+1);
        for(int j=i+2;j<n;j+=2) if(check(s,i,j-1)) dp2[i]=min(dp2[i],rec2(s,j));
        return dp2[i];
    }
public:
    string lexicographicallySmallestString(string s) {
        return rec2(s,0);
    }
};