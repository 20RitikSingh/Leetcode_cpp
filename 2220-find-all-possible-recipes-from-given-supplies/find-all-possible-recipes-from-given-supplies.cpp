class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_set<string> got;
        for(auto s:supplies) got.insert(s);
        // vector<unordered_set<string>> ing(n);
        // for(int i=0;i<n;i++) ing[i]=unordered_set<string>(ingredients[i].begin(), ingredients[i].end());
        vector<string> res;
        for(int i=0;i<n*n;i++){
            if(recipes[i%n]=="") continue;
            bool f=1;
            for(string s:ingredients[i%n]) if(got.count(s)==0){ f=0; break;}
            if(f){got.insert(recipes[i%n]); res.push_back(recipes[i%n]); recipes[i%n]="";}
        }
        return res;
    }
};