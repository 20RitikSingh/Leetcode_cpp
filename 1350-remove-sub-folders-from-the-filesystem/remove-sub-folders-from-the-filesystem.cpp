class Trie{
    unordered_set<string> set;
public:
    void add(string s){
        set.insert(s);
    }
    bool match(string s){
        string t;
        for(int i=0;i<s.size();i++){
            while(i<s.size() && s[i]!='/') t.push_back(s[i++]);
            if(set.count(t)) return 1;
            t.push_back('/');
        }
        return 0;
    }
};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans;
        Trie t;
        for(auto s:folder){
            if(t.match(s)) continue;
            else t.add(s),ans.push_back(s);
        }
        return ans;
    }
};