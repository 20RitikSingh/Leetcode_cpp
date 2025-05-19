class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n=v.size(),res=0;
        vector<int> prevmin(n,-1),nxtmin(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && v[st.top()]>=v[i]) st.pop();
            if(st.size()) prevmin[i]=st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(st.size() && v[st.top()]>=v[i]) st.pop();
            if(st.size()) nxtmin[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int area=(nxtmin[i]-prevmin[i]-1)*v[i];
            res=max(res,area);
        }
        return res;
    }
};