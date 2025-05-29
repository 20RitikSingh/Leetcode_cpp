class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        for(int i=0;i<a.size();i++){
            bool f=1;
            for(int j=0;j<b.size();j++){
                if(a[(i+j)%a.size()]!=b[j]){
                    f=0;
                    break;
                }
            }
            if(f) return (i+b.size()+a.size()-1)/a.size();
        }
        return -1;
    }
};