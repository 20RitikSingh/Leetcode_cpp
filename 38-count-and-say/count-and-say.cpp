class Solution {
    string RLE(string s){
        string res="1"+string(1,s[0]);
        for(int i=1;i<s.size();i++)
            if(res.back()==s[i]) res[res.size()-2]++;
            else res=res+"1"+string(1,s[i]);
        return res;
    }
public:
    string countAndSay(int n) {
        string s="1";
        for(int k=1;k<n;k++) s=RLE(s);
        return s;
    }
};