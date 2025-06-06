class Solution {
public:
    string robotWithString(string s) {
        int n=s.size(),i=0,j=0;
        stack<char> st;
        string nxt=s;
        for(int i=n-2;i>=0;i--) nxt[i]=min(s[i],nxt[i+1]);
        while(i<n){
            if(st.size() && st.top()<=nxt[i]){
                nxt[j++]=st.top();
                st.pop();
            }else st.push(s[i++]);
        }
        while(st.size()){ nxt[j++]=st.top(); st.pop();}
        return nxt;
    }
};