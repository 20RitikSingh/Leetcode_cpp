class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        set<pair<int,int>> set;
        sort(items.begin(),items.end());
        int mx=-1;
        for(auto i:items){ if(i[1]>mx) set.insert({i[0],i[1]}); mx=max(mx,i[1]);}
        vector<int> ans(q.size());
        for(int i=0;i<ans.size();i++){
            auto it=set.lower_bound({q[i],1e9+1});
            if(it!=set.begin()){
                it--;
                ans[i]=it->second;
            } 
        }
        return ans; 
    }
};