class Solution {
    int v[1001];
    int rec(int n,int s,int k){
        if(s+n==k) return 1;
        bool f=0;
        int a=1;
        while(a<n){
            a*=10;
            f|=rec(n/a,s+n%a,k);
        }
        return f;
    }
    void pre(){
        v[1]=1;
        for(int i=2;i<1001;i++){
            v[i]=v[i-1];
            if(rec(i*i,0,i)) v[i]+=i*i;
        }
    }
public:
    int punishmentNumber(int n) {
        pre();
        return v[n];
    }
};