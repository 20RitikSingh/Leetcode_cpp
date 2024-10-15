class Solution {
public:
    long long minimumSteps(string s) {
        long long res=0,cnt=0,n=s.size();
        for(int i:s) cnt+=i-'0';
        for(int i=0;i<n-cnt;i++) if(s[i]=='1') res-=i;
        for(int i=n-cnt;i<n;i++) if(s[i]=='0') res+=i; 
        return res;
    }
};