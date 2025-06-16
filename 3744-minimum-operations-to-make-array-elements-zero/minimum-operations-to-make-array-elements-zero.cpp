class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res=0;
        for(auto q:queries){
            long long clicks=0;
            for(int i=1;i<31;i++){
                clicks+=1LL*(i+1)/2*max(0,min((1<<i)-1,q[1])-max(1<<(i-1),q[0])+1);
            }
            res+=(clicks+1)/2;
        }
        return res;
    }
};