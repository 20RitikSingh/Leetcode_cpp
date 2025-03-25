class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x,y,res;
        for(auto r:rectangles){
            x.push_back({r[0],r[2]});
            y.push_back({r[1],r[3]});
        }
        sort(x.begin(),x.end());
        for(auto i:x){
            // cout<<i[0]<<","<<i[1]<<" ";
            if(res.empty() || res.back()[1]<=i[0]) res.push_back(i);
            else res.back()[1]=max(res.back()[1],i[1]); 
        }
        // cout<<endl;
        // for(auto i:res) cout<<i[0]<<","<<i[1]<<" ";
        if(res.size()>2) return 1;
        res=vector<vector<int>>();
        sort(y.begin(),y.end());
        for(auto i:y){
            if(res.empty() || res.back()[1]<=i[0]) res.push_back(i);
            else res.back()[1]=max(res.back()[1],i[1]); 
        }
        if(res.size()>2) return 1;
        return 0;
    }
};