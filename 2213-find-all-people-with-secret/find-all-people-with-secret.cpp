class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knows(n,1e9);
        vector<set<pair<int,int>>> adj(n);
        set<tuple<int,int,int>> set;

        for(auto m:meetings){
            adj[m[0]].insert({m[2],m[1]});
            adj[m[1]].insert({m[2],m[0]});
            set.insert({m[2],m[0],m[1]});
        }

        knows[0]=0;
        knows[firstPerson]=0;

        while(set.size()){
            auto it=set.begin();
            auto [t,x,y]=*it;
            set.erase(it);
            if(knows[y]<=t && knows[x]>t){
                knows[x]=t;
                auto it1=adj[x].lower_bound({t,-1});
                while(it1!=adj[x].end()){
                    set.insert({it1->first,x,it1->second});
                    it1++;
                }
            }
            if(knows[x]<=t && knows[y]>t){
                knows[y]=t;
                auto it1=adj[y].lower_bound({t,-1});
                while(it1!=adj[y].end()){
                    set.insert({it1->first,y,it1->second});
                    it1++;
                }
            }
        }

        vector<int> res;
        for(int i=0;i<n;i++){
            if(knows[i]<1e9) res.push_back(i);
        }
        return res;
    }
};