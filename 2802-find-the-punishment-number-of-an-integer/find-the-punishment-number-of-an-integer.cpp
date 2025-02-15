class Solution {
    int v[1001];
    int rec(int n,int s,int k){
        if(s+n==k) return 1;
        bool f=0;
        int a=1;
        while(a<n){
            a*=10;
            f|=rec(n/a,s+n%a,k);
            if(f) return 1;
        }
        return 0;
    }
    void pre(){
        v[1]=1;
        for(int i=2;i<1001;i++){
            v[i]=v[i-1];
            if(rec(i*i,0,i)) v[i]+=i*i;
        }
    }
public:
    Solution(){
        pre();
    }
    int punishmentNumber(int n) {
        return v[n];
    }
};