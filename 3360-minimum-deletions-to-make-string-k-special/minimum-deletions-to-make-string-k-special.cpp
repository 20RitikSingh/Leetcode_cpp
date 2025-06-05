class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for(char ch:word) freq[ch-'a']++;
        sort(freq.begin(),freq.end());
        int res=1e9,p=0;
        for(int i=0;i<26;i++){
            int c=p;
            for(int j=i+1;j<26;j++) c+=max(0,freq[j]-freq[i]-k);
            res=min(c,res);
            p+=freq[i];
        }
        return res;
    }
};