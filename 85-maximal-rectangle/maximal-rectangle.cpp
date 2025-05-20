class Solution {
    int rec(vector<int>& v) {
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
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        int res=0,n=grid.size(),m=grid[0].size();
        vector<int> nxt(m, n);
        for (int k = n - 1; k >= 0; k--) {
            vector<int> v(m);
            for (int j = 0; j < m; j++) {
                if (grid[k][j] == '0') nxt[j] = k;
                v[j] = nxt[j] - k;
            }
            res=max(res,rec(v));
        }

        return res;
    }
};