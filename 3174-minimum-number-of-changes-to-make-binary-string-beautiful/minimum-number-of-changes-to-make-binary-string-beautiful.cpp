class Solution {
public:
    int minChanges(string s) {
        int prev=s[0],c=0,k=0,lastodd=-1;
        vector<int> v;
        for(int i:s){
            if(prev!=i){
                // if(c%2 && lastodd>=0) k+=i-lastodd;
                // if(c%2) lastodd=i-1;
                v.push_back(c);
                c=1;
                prev=i;
            }else c++;
        }
        v.push_back(c);
        bool f=0;
        for(int i:v){
            if(i%2){
                f=!f;
                k+=f;
                continue;
            }
            if(f) k+=1;
        }
        return k;
    }
};