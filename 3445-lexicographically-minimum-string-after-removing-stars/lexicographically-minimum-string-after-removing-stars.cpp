class Solution {
public:
    string clearStars(string s) {
        set<tuple<char,int>> set;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                auto [ch,j]=*set.begin();
                s[0-j]='*';
                set.erase(set.begin());
            }else set.insert({s[i],0-i});
        }
        // cout<<s<<endl;
        string res;
        for(char ch:s) if(ch!='*') res.push_back(ch);
        return res;
    }
};