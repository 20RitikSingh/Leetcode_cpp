class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int k=1;k<n;k++){
            string res="";
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
            s=res;
        }
        return s;
    }
};