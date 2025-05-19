class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size(),res=0;
        vector<int> prevmin(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && v[st.top()]>=v[i]) st.pop();
            if(st.size()) prevmin[i]=st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1,nxtmin=n;i>=0;nxtmin=n,i--){
            while(st.size() && v[st.top()]>=v[i]) st.pop();
            if(st.size()) nxtmin=st.top();
            st.push(i);
            res=max(res,(nxtmin-prevmin[i]-1)*v[i]);
        }
        return res;
    }
};