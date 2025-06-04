class Solution {
public:
    string answerString(string word, int numFriends) {
        vector<string> v;
        int k=word.size()-numFriends+1;
        if(k==word.size()) return word;
        for(int i=0;i<word.size();i++){
            v.push_back(word.substr(i,min(k,(int)word.size()-i)));
        }
        sort(v.begin(),v.end());
        return v.back();
    }
};