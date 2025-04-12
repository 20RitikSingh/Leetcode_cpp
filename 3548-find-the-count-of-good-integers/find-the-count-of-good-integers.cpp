class Solution {
    long long pow(long long x,long long y){
        if(y==0) return 1;
        if(y==1) return x;
        long long k=pow(x,y/2);
        if(y%2) return x*k*k;
        return k*k;
    }
    long long pal(int x){
        long long res=x;
        while(x>0){
            res*=10;
            res+=x%10;
            x/=10;
        }
        return res; 
    }
    long long palodd(int x){
        long long res=x;
        x/=10;
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
        // cout<<s<<endl;
        long long res=0;
        for(int i=1;i<10;i++){
            long long x=fact[d-1];
            if(s[i]==0) continue;
            for(int j=0;j<10;j++){
                if(j==i) x/=fact[s[j]-1];
                else x/=fact[s[j]];
            }
            res+=x;
        }
        return res;
    }
public:
    long long countGoodIntegers(int n, int k) {
        for(int i=1;i<11;i++) fact[i]=fact[i-1]*i;
        if(n%2){
            int d=n/2;
            int x=pow(10,d);
            long long c=0;
            for(int i=0;i+x<pow(10,d+1);i++){
                long long t=palodd(i+x);
                if(t%k==0){
                    c+=perm(t);
                    // cout<<t<<endl;
                }
            }
            return c;
        }
        int d=n/2;
        int x=pow(10,d-1);
        long long c=0;
        // cout<<x<<endl;
        for(int i=0;i+x<pow(10,d);i++){
            long long t=pal(i+x);
            if(t%k==0){
                c+=perm(t);
                // cout<<t<<endl;
                // cout<<perm(t)<<endl;
            }
        }
        return c;
    }
};