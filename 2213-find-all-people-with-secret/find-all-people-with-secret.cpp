class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knows(n,1e9);
        vector<set<pair<int,int>>> adj(n);
        set<tuple<int,int,int>> set;

        for(auto m:meetings){
            adj[m[0]].insert({m[2],m[1]});
            adj[m[1]].insert({m[2],m[0]});
            set.insert({m[2],min(m[0],m[1]),max(m[0],m[1])});
        }

        knows[0]=0;
        knows[firstPerson]=0;

        while(set.size()){
            auto it=set.begin();
            auto [t,x,y]=*it;
            set.erase(it);
            for(int i=0;i<2;i++){
                if(knows[y]<=t && knows[x]>t){
                    knows[x]=t;
                    auto it=adj[x].lower_bound({t,-1});
                    while(it!=adj[x].end()){
                        set.insert({it->first,min(x,it->second),max(x,it->second)});
                        it++;
                    }
                }
                swap(x,y);
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(knows[i]<1e9) res.push_back(i);
        }
        return res;
    }
};