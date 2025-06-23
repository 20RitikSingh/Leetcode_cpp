class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        unordered_set<int> set;
        vector<int> res;
        for(int i:a) set.insert(i);
        for(int i:b) if(set.count(i)) res.push_back(i),set.erase(i);
        return res;
    }
};