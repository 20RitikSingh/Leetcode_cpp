class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0,center=0;
        int mp[26*26];
        for(auto &t:words){
            mp[(t[0]-'a')*26+(t[1]-'a')]++;
        }
        for(int t=0;t<26*26;t++){
            // cout<<t<<" "<<mp[t]<<endl;
            if(!mp[t]) continue;
            int s=(t%26)*26+t/26;
            if(t%26==t/26){ 
                center+=mp[t]%2;
                res+=mp[t]/2;
            }
            else if(mp[s]){ 
                res+=min(mp[t],mp[s]);
            }
            mp[t]=0;
            mp[s]=0;
            // cout<<res<<endl;
        }
        return 2*(2*res+(center>0));
    }
};