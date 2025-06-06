class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        stack<char> st;
        vector<char> nxt(n,s[n-1]);
        for(int i=n-2;i>=0;i--){
            nxt[i]=min(s[i],nxt[i+1]);
        }
        string res=s;
        int i=0,j=0;
        while(i<n){
            if(st.size() && i<n && st.top()<=nxt[i]){
                res[j++]=st.top();
                st.pop();
            }else st.push(s[i++]);
        }
        while(st.size()){ res[j++]=st.top(); st.pop();}
        return res;
    }
};