class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n=acc.size();
        vector<int> parent(n);
        for(int i=0;i<n;i++) parent[i]=i;
        unordered_map<string,int> mp;
        vector<unordered_set<string>> mem(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                if(mp.find(acc[i][j])!=mp.end()){ 
                    int x=mp[acc[i][j]];
                    while(x!=parent[x]) x=parent[x];
                    if(parent[i]!=x){
                        parent[parent[i]]=x;
                    }
                    parent[i]=x; 
                }
                mp[acc[i][j]]=i;
            }
        }
        for(int i=0;i<n;i++){
            int x=parent[i];
            while(x!=parent[x]) x=parent[x];
            parent[i]=x;
        }
        // for(int i=0;i<n;i++) cout<<i<<"->"<<parent[i]<<endl;
        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++) mem[parent[i]].insert(acc[i][j]);
        }
        vector<vector<string>> res;
        for(int i=0;i<n;i++){
           if(mem[i].empty()) continue;
           res.push_back({acc[i][0]});
           for(auto s:mem[i]) res.back().push_back(s); 
        }
        for(auto &v:res){
            sort(v.begin()+1,v.end());
        }
        return res;
    }
};