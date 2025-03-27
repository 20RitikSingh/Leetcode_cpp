class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        unordered_set<string> got;
        for(auto s:supplies) got.insert(s);
        vector<unordered_set<string>> ing(n);
        for(int i=0;i<n;i++) ing[i]=unordered_set<string>(ingredients[i].begin(), ingredients[i].end());
        vector<string> res;
        queue<string> q;
        for(auto s:supplies) q.push(s);
        while(q.size()){
            for(int i=0;i<n;i++){
                if(recipes[i]=="") continue;
                ing[i].erase(q.front());
                if(ing[i].empty()){
                    res.push_back(recipes[i]);
                    q.push(recipes[i]);
                    recipes[i]="";
                }
            }
            q.pop();
        }
        return res;
    }
};