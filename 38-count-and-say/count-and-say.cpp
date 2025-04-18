class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string res="",s=countAndSay(n-1);
        // cout<<n-1<<" "<<s<<endl;
        int c=1,e=s[0];
        for(int i=1;i<s.size();i++){
            if(e==s[i]) c++;
            else{
                res.push_back(c+'0');
                res.push_back(e);
                c=1;
                e=s[i];
            }
        }
        res.push_back(c+'0');
        res.push_back(e);
        return res;
    }
};