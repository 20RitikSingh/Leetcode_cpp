class Solution {
    long long pow(long long x,long long y){
        if(y==0) return 1;
        long long k=pow(x,y/2);
        if(y%2) return x*k*k;
        return k*k;
    }
    long long pal(int x,int p){
        long long res=x;
        x/=pow(10,p);
        while(x>0){
            res*=10;
            res+=x%10;
            x/=10;
        }
        return res; 
    }
    unordered_set<string> set;
    vector<int> fact=vector<int>(11,1);
    long long perm(long long t){
        string s(10,0);
        int d=0;
        while(t>0){
            s[t%10]++;
            t/=10;
            d++;
        }
        if(set.count(s)) return 0;
        set.insert(s);
        long long res=0;
        for(int i=1;i<10;i++){
            long long x=fact[d-1];
            if(s[i]==0) continue;
            for(int j=0;j<10;j++) x/=fact[s[j]-(i==j)];
            res+=x;
        }
        return res;
    }
public:
    long long countGoodIntegers(int n, int k) {
        for(int i=1;i<11;i++) fact[i]=fact[i-1]*i;
        long long c=0,d=n/2,x=pow(10,d-1+n%2);
        for(int i=0;i+x<pow(10,d+n%2);i++){
            long long t=pal(i+x,n%2);
            if(t%k==0) c+=perm(t);
        }
        return c;
    }
};