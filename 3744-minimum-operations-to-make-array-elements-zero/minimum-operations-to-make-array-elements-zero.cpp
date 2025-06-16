class Solution {
    int count(int l,int r,int b){
        int mi=1<<(b-1);
        int mx=(1<<b)-1;
        mi=max(mi,l);
        mx=min(mx,r);
        return max(0,mx-mi+1);
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res=0;
        for(auto q:queries){
            long long clicks=0;
            for(int i=1;i<31;i++){
                clicks+=1LL*(i+1)/2*count(q[0],q[1],i);
            }
            res+=(clicks+1)/2;
        }
        return res;
    }
};