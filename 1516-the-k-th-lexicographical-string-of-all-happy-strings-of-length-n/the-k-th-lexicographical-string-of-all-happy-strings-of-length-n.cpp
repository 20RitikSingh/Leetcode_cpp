class Solution {
public:
    string getHappyString(int n, int k) {
        string s;
        set<char> set={'a','b','c'};
        while(n){
            int l=1,h=pow(2,n-1),f=1;
            for(auto it:set){
                if(k<=h){
                    char ch=it;
                    s.push_back(ch);
                    set.insert('a');
                    set.insert('b');
                    set.insert('c');
                    set.erase(ch);
                    n--;
                    f=0;
                    k-=l-1;
                    goto skip;
                }
                l+=pow(2,n-1);
                h+=pow(2,n-1);
            }
            skip:
            if(f) break;
        }
        return s;
    }
};