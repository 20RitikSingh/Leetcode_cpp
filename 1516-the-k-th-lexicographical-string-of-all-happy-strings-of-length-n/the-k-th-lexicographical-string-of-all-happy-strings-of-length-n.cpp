class Solution {
    vector<string> v;
    void rec(int n,string s,char prev){
        if(s.size()==n){
            v.push_back(s);
            return;
        }
        bool ar[4]={1,1,1,0};
        ar[prev-'a']=0;
        for(int i=0;i<3;i++) if(ar[i]) rec(n,s+string(1,'a'+i),'a'+i);
    }
public:
    string getHappyString(int n, int k) {
        rec(n,"",'d');
        if(k>v.size()) return "";
        return v[k-1];
    }
};