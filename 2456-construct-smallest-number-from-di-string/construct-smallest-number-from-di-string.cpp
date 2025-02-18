class Solution {
public:
    string smallestNumber(string p) {
        string s;
        int a=1,d=0;
        for(int i=0;i<p.size();i++){
            if(p[i]=='D'){
                d++;
                continue;
            }
            if(d){
                string t;
                for(int i=0;i<=d;i++){
                    t.push_back('0'+a);
                    a++;
                }
                reverse(t.begin(),t.end());
                s+=t;
                d=0;
                continue;
            }
            if(p[i]=='I'){
                s.push_back('0'+a);
                a++;
            }
        }
        if(d){
            string t;
            for(int i=0;i<=d;i++){
                if(a>9) continue;
                t.push_back('0'+a);
                a++;
            }
            reverse(t.begin(),t.end());
            s+=t;
            d=0;
        }
        if(s.size()==p.size()) s.push_back('0'+a);
        return s;
    }
};