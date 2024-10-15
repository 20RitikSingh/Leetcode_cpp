class Solution {
public:
    long long minimumSteps(string s) {
        long long b=0,e=s.size()-1,res=0,n=s.size();
        while(b<e){
            while(b<e && s[b]!='1') b++;
            while(b<e && s[e]!='0') e--;
            if(b==e) return res;
            res+=e-b;
            e--;
            b++;
        }
        return res;
    }
};