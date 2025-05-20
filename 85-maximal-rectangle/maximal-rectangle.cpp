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
        vector<vector<int>> first(m,vector<int>(n,n));
        for(int j=0;j<m;j++){
            if(grid[n-1][j]=='0') first[j][n-1]=n-1;
            for(int k=n-2;k>=0;k--){
                if(grid[k][j]=='0') first[j][k]=k;
                else first[j][k]=first[j][k+1];
            }
        }
        for(int k=0;k<n;k++){
            vector<int> v(m);
            for(int j=0;j<m;j++){
                v[j]=first[j][k]-k;
            }
            res=max(res,rec(v));
        }
        return res;
    }
};