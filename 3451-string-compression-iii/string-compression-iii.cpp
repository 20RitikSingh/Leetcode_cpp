class Solution {
public:
    string compressedString(string word) {
        string comp="0";
        comp.push_back(word[0]);
        for(char c:word){
            int x=comp[comp.size()-2];
            char k=comp[comp.size()-1];
            if(x<'9' && k==c) comp[comp.size()-2]++;
            else{ 
                comp.push_back('1');
                comp.push_back(c);
            }
        }
        return comp;
    }
};