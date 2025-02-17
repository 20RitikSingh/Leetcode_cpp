class Solution {
    int fact[8];
    int calc(string v){
        if(set.count(v)) return 0;
        set.insert(string(v));
        int a=0,b=1;
        for(int i:v){
            a+=i;
            b*=fact[i];
        }
        return fact[a]/b;
    }
    unordered_set<string> set;
    int ans=0;
    int rec(string u,int idx){
        if(idx>=u.size()) return 0;
        for(int i=0;i<=u[idx];i++){
            u[idx]-=i;
            ans+=calc(u);
            rec(u,idx+1);
            u[idx]+=i;
        }
        return 0;
    }
public:
    int numTilePossibilities(string tiles) {
        fact[0]=1;
        for(int i=1;i<8;i++) fact[i]=i*fact[i-1];
        string u,v(26,'a'-'a');
        for(char ch:tiles){
            v[ch-'A']++;
        }
        for(int i:v){
            if(i) u.push_back(i);
        }
        rec(u,0);
        return ans-1;
    }
};