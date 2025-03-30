class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res,v(26),u(26);
        for(char i:s){
            v[i-'a']++;
        }
        int x=-1;
        for(int i=0;i<s.size();i++){
            u[s[i]-'a']++;
            bool f=1;
            for(int i=0;i<26;i++){
                if(u[i] && u[i]!=v[i]){ f=0; break;}
            }
            if(f){ res.push_back(i-x); x=i;}
        }
        return res;
    }
};