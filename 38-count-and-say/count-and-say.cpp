unordered_map<int,string> mp;
class Solution {
    string rle(string s){
        string res;
        int c=0;
        char sel=s[0];
        for(char ch:s){
            if(ch==sel) c++;
            else{ 
                res.push_back(c+'0');
                res.push_back(sel);
                sel=ch;
                c=1;
            }
        }
        res.push_back(c+'0');
        res.push_back(sel);
        return res;
    }
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(!mp.count(n)) mp[n]=rle(countAndSay(n-1));
        return mp[n];
    }
};