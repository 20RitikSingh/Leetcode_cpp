class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        unordered_set<string> set;
        vector<string> res;
        for(string s:folder){
            string t=s;
            bool f=1;
            res.push_back(s);
            while(!t.empty()){
                if(set.count(t)){ res.pop_back(); f=0; break;}
                while(!t.empty() && t.back()!='/') t.pop_back();
                t.pop_back();
            }
            if(f) set.insert(s);
        }
        return res;
    }
};