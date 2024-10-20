class Solution {
public:
    bool parseBoolExpr(string exp) {
        stack<char> st;
        for(char ch:exp){
            if(ch==',') continue;
            if(ch==')'){
                bool aand=1,oor=0;
                while(st.top()!='('){
                    aand&=st.top()=='t'?1:0;
                    oor|=st.top()=='t'?1:0;
                    st.pop();
                }
                st.pop();
                char x=st.top();
                st.pop();
                if(x=='!'){
                    st.push(oor?'f':'t');
                }else if(x=='&'){
                    st.push(aand?'t':'f');
                }else if(x=='|'){
                    st.push(oor?'t':'f');
                }
                continue;
            }
            st.push(ch);
        }
        return st.top()=='t'?1:0;
    }
};