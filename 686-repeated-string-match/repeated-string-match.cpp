class Solution {
    bool check(string s,string t){
        // cout<<s<<" "<<t<<endl;
        for(int i=0;i+t.size()<=s.size();i++){
            if(!s.compare(i,t.size(),t)) return 1;
        }
        return 0;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int c=0;
        string s;
        while(s.size()<b.size()){
            s+=a;
            c++;
        }
        if(check(s,b)) return c;
        if(check(s+a,b)) return c+1;
        return -1;
    }
};