class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        unordered_map<string,int> mp;
        vector<unordered_set<string>> mem(n);
        vector<vector<string>> res;
        vector<int> parent(n);
                
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=1;j<acc[i].size();j++){
                if(mp.find(acc[i][j])!=mp.end()){ 
                    while(mp[acc[i][j]]!=parent[mp[acc[i][j]]]) mp[acc[i][j]]=parent[mp[acc[i][j]]];
                    if(parent[i]!=mp[acc[i][j]]) parent[parent[i]]=mp[acc[i][j]];
                    parent[i]=mp[acc[i][j]]; 
                }else mp[acc[i][j]]=i;
            }
        }

        for(int i=0;i<n;i++){
            while(parent[i]!=parent[parent[i]]) parent[i]=parent[parent[i]];
            for(int j=1;j<acc[i].size();j++) mem[parent[i]].insert(acc[i][j]);
        }
        
        for(int i=0;i<n;i++){
            if(mem[i].empty()) continue;
            res.push_back({acc[i][0]});
            for(auto s:mem[i]) res.back().push_back(s); 
        }
        
        for(auto &v:res) sort(v.begin()+1,v.end());
        return res;
    }
};