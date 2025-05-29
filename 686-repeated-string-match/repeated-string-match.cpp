
class Solution {
    int inv(int d){
        return pow(d,mod-2);
    }
    int pow(int x,int y){
        if(!y) return 1;
        int res=pow(x,y/2);
        if(y%2) return (((1LL*res*res)%mod)*x)%mod;
        return (1LL*res*res)%mod;
    }
    int d=26,mod=1e9+7;
    int hash(string s,int n){
        long long res=0;
        for(int i=0;i<n;i++){
            res+=1LL*s[i]*pow(d,i);
            res%=mod;
        }
        return res;
    }
    int roll(int &h,int n,char rem,char ins){
        h-=rem;
        h=(1LL*h*inv(d))%mod;
        h=(1LL*h+(1LL*ins*pow(d,n-1))%mod)%mod;
        return h;
    }
public:
    int repeatedStringMatch(string a, string b) {
        for(auto &i:a) i-='a';
        for(auto &i:b) i-='a';
        string s;
        while(s.size()<=b.size()) s+=a;
        s+=a;
        int n=b.size();
        int h2=hash(b,n);
        int h1=hash(s,n);
        if(h1==h2) return (n+a.size()-1)/a.size();
        for(int i=0;i+n<=s.size();i++){
            roll(h1,n,s[i],s[i+n]);
            if(h1==h2) return (i+n+a.size())/a.size();
        }
        return -1;
    }
};