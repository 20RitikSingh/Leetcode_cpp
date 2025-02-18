class Solution {
    void perm(string s,vector<string> &v,int idx=0){
        if(idx>=s.size()){
            // cout<<s<<endl;
            v.push_back(s);
            return;
        }
        for(int i=idx;i<s.size();i++){
            swap(s[i],s[idx]);
            perm(s,v,idx+1);
            swap(s[i],s[idx]);
        }
        return;
    }
    bool isvalid(string s,string pattern){
        for(int i=0;i<pattern.size();i++){
            if(pattern[i]=='I' && s[i]>s[i+1]) return 0;
            if(pattern[i]=='D' && s[i]<s[i+1]) return 0;
        }
        return 1;
    }
public:
    string smallestNumber(string pattern) {
        string s="123456789";
        s=s.substr(0,pattern.size()+1);
        vector<string> v;
        perm(s,v);
        for(auto str:v){
            if(isvalid(str,pattern)) return str;
        }
        return v.back();
    }
};