class Solution {
    int solve(int num,int i,int j){
        stack<int> st;
        while(num){
            st.push(num%10);
            num/=10;
        }
        if(st.top()==i && j==0) return -1;
        while(st.size()){
            if(st.top()==i) num=num*10+j;
            else num=num*10+st.top();
            st.pop();
        }
        return num;
    }
public:
    int maxDiff(int num) {
        int mx=num,mi=num;
        for(int j=0;j<10;j++)
        for(int i=0;i<10;i++){
            int x=solve(num,i,j);
            if(x<0) continue;
            mi=min(mi,x);
            mx=max(mx,x);
        }
        return mx-mi;
    }
};