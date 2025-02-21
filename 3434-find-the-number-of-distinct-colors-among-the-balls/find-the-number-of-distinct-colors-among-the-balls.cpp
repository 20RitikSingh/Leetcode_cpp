class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> c2f,b2c;
        vector<int> res;
        int n=1;
        c2f[0]=limit+1;
        for(auto q:queries){
            if(c2f[b2c[q[0]]]==1){
                n--;
            }
            c2f[b2c[q[0]]]--;
            if(c2f[q[1]]==0){
                n++;
            }
            b2c[q[0]]=q[1];
            c2f[q[1]]++;
            if(c2f[0]) res.push_back(n-1);
            else res.push_back(n);
        }
        return res;

            // for(int i=0;i<6;i++){
            //     cout<<i<<":"<<b2c[i]<<" ";
            // }
            // cout<<endl;
            // for(int i=0;i<6;i++){
            //     cout<<i<<":"<<c2f[i]<<" ";
            // }
            // cout<<endl;
            // cout<<endl;
    }
};