class Solution {
    int pow(int x,int y){
        if(!y) return 1;
        int ans=pow(x,y/2);
        ans=(1LL*ans*ans)%mod;
        if(y%2) ans=(1LL*ans*x)%mod;
        return ans;
    }
    int inv(int x){ return pow(x,mod-2);}
    int mod=1e9+7;
    int fact[1001],invfact[1001];
    int calc(int x,int y){
        if(!x || !y) return 1;
        return (1LL*fact[x+y]*(1LL*invfact[x]*invfact[y]%mod))%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        fact[0]=1,invfact[0]=1;
        for(int i=1;i<1001;i++){ 
            fact[i]=(1LL*fact[i-1]*i)%mod;
            invfact[i]=(1LL*invfact[i-1]*inv(i))%mod;
        }
        queue<vector<int>> q;
        q.push(nums);
        int res=1;
        while(q.size()){
            auto v=q.front();
            // for(auto i:v) cout<<i<<" ";cout<<endl;
            q.pop();
            vector<int> x,y;
            for(int i=1;i<v.size();i++){
                if(v[i]<v[0]) x.push_back(v[i]);
                else y.push_back(v[i]);
            }
            if(x.size()) q.push(x);
            if(y.size()) q.push(y);
            res=(1LL*res*calc(x.size(),y.size()))%mod;
        }
        return res-1;
    }
};