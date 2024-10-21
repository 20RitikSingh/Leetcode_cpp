class Solution {
    unordered_set<string> set;
    int rec(string s,int idx=0){
        int n=s.size(),res=0;
        if(idx==n){
            return set.size();
        }
        for(int i=1;i<=n-idx;i++){
            string t=s.substr(idx,i);
            if(set.count(t)) continue;
            set.insert(t);
            res=max(res,rec(s,idx+i));
            set.erase(t);
        }
        return res;
    }
public:
    int maxUniqueSplit(string s) {
        return rec(s);
    }
};