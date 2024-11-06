class Solution {
public:
    string compressedString(string word) {
        string comp="0"+string(1,word[0]);
        for(char c:word){
            if(comp[comp.size()-2]<'9' && comp.back()==c) comp[comp.size()-2]++;
            else{ 
                comp+="1"+string(1,c);
            }
        }
        return comp;
    }
};