class Solution {
    unordered_set<string> set;
    int res=1;
    int rec(string s){
        if(s==""){
            res=max(res,(int)set.size());
            return 0;
        }
        int n=s.size();
        for(int i=1;i<=n;i++){
            if(set.count(s.substr(0,i))) continue;
            set.insert(s.substr(0,i));
            rec(s.substr(i,n-i));
            set.erase(s.substr(0,i));
        }
        return 0;
    }
public:
    int maxUniqueSplit(string s) {
        rec(s);
        return res;
    }
};