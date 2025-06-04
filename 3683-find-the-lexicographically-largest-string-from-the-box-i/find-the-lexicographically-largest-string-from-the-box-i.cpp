class Solution {
public:
    string answerString(string word, int numFriends) {
        string v;
        int k=word.size()-numFriends+1;
        if(k==word.size()) return word;
        for(int i=0;i<word.size();i++)
        if(v<word.substr(i,min(k,(int)word.size()-i))) v=word.substr(i,min(k,(int)word.size()-i));
        return v;
    }
};