int mod=1e9+7;
vector<vector<long long>> table;
struct init{
    init(){
        int n=1000;
        table.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
    }
};
init init;
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        queue<vector<int>> q;
        q.push(nums);
        int res=1;
        while(q.size()){
            auto v=q.front();
            q.pop();
            vector<int> x,y;
            for(int i=1;i<v.size();i++){
                if(v[i]<v[0]) x.push_back(v[i]);
                else y.push_back(v[i]);
            }
            if(x.size()) q.push(x);
            if(y.size()) q.push(y);
            res=(1LL*res*table[x.size()+y.size()][x.size()])%mod;
        }
        return res-1;
    }
};