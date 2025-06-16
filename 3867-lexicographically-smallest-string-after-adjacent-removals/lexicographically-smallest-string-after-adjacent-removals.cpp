class Solution {
    int dp[250][250];
    bool check(string &s,int low,int high){
        if(high<low) return 1;
        if(high-low==1) return (abs(s[low]-s[high])==1 || abs(s[low]-s[high])==25);
        if(dp[low][high]) return dp[low][high]-1;
        bool f=0;
        if(abs(s[low]-s[high])==1 || abs(s[low]-s[high])==25) f|=check(s,low+1,high-1);
        for(int i=low+1;i<high-1;i+=2){
            f|=check(s,low,i)&check(s,i+1,high);
        }
        dp[low][high]=f+1;
        return f;
    }
    string dp2[250];
    string rec2(string &s,int i){
        int n=s.size();
        if(check(s,i,n-1)) return "";
        if(dp2[i]!="") return dp2[i];
        string res=s.substr(i,1)+rec2(s,i+1);
        for(int j=i+2;j<n;j+=2){
            if(check(s,i,j-1)) res=min(res,rec2(s,j));
        }
        dp2[i]=res;
        return res;
    }
public:
    string lexicographicallySmallestString(string s) {
        return rec2(s,0);
    }
};