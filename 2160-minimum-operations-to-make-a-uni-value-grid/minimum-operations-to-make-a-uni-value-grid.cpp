class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(auto i:grid) for(auto j:i) v.push_back(j);
        sort(v.begin(),v.end());
        int ans=0,c=v[v.size()/2];
        for(int i:v){
            if(abs(c-i)%x) return -1;
            ans+=abs(c-i)/x;        
        }
        return ans;
    }
};