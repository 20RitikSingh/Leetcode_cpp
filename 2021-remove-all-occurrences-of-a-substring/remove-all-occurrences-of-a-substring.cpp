class Solution {
    int issubstr(string &s,string part){
        for(int i=0;i<s.size()-part.size()+1;i++){
            if(s.substr(i,part.size())==part){ 
                s=s.substr(0,i)+s.substr(i+part.size(),s.size()-i-part.size());
                return i;
            }
        }
        return -1;
    }
public:
    string removeOccurrences(string s, string part) {
        while(s.size()>=part.size()){
            int i=issubstr(s,part);
            if(i<0) return s; 
        }
        return s;
    }
};