class Solution {
public:
    int maxDiff(int num) {
        int mx=0,mi=0,t=0,u=0,f=0;
        stack<int> st;
        while(num){
            st.push(num%10);
            if(num%10<9) t=num%10;
            if(num%10>1) u=num%10;
            num/=10;
        }
        if(u==st.top()) f=1;
        while(st.size()){
            if(st.top()==t){
                mx=mx*10+9;
            }else{
                mx=mx*10+st.top();
            }
            if(st.top()==u){
                mi=mi*10+f;
            }else{
                mi=mi*10+st.top();
            }
            st.pop();
        }
        return mx-mi;
    }
};