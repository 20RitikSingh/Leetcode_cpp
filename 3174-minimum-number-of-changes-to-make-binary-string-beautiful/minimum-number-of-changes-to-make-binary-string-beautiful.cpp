class Solution {
public:
    int minChanges(string s) {
        int prev=s[0],c=0,k=0,f=0;
        for(int i:s){
            if(prev!=i){
                if(c%2){
                    f=!f;
                    k+=f;
                }else if(f) k++;
                c=1;
                prev=i;
            }else c++;
        }
        if(c%2){
            f=!f;
            k+=f;
        }else if(f) k++;
        return k;
    }
};