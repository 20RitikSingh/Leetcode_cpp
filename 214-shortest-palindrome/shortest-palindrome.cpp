class Solution {
    int d=26,mod=1e9+7;
    int pow(int x,int y){
        if(!y) return 1;
        int res=pow(x,y/2);
        res=(1LL*res*res)%mod;
        if(y%2) return (1LL*res*x)%mod;
        return res;
    }
    int longestPrefixPalindrome(string s){
        int h1=0,h2=0,n=s.size(),res=0;
        for(auto &ch:s) ch-='a';
        for(int i=0;i<n;i++){
            h1=(1LL*h1*d+s[i])%mod;
            h2=(h2+1LL*pow(d,i)*s[i])%mod;
            if(h1==h2) res=i+1;
        }
        return res;
    }
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        int x=longestPrefixPalindrome(s);
        string tmp=s.substr(x,n-x);
        reverse(tmp.begin(),tmp.end());
        return tmp+s;
    }
};