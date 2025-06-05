class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for(char ch:word) freq[ch-'a']++;
        sort(freq.begin(),freq.end());
        int res=1e9,p=0;
        for(int i=0;i<26;i++){
            int c=p;
            // cout<<c<<endl;
            auto it=lower_bound(freq.begin(),freq.end(),freq[i]+k+1);
            while(it!=freq.end()){
                c+=*it-freq[i]-k;
                it++;
            }
            res=min(c,res);
            p+=freq[i];
        }
        return res;
    }
};