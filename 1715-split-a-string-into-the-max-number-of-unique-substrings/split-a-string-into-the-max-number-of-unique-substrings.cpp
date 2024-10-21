class Solution {
    unordered_set<string> set;
    // vector<int> 
    int rec(string s,int idx=0){
        int n=s.size(),res=0;
        if(idx==n){
            return set.size();
        }
        for(int i=1;i<=n-idx;i++){
            if(set.count(s.substr(idx,i))) continue;
            set.insert(s.substr(idx,i));
            res=max(res,rec(s,idx+i));
            set.erase(s.substr(idx,i));
        }
        return res;
    }
public:
    int maxUniqueSplit(string s) {
        return rec(s);
    }
};