class Solution {
    int rec(vector<int>& v) {
        for(int i:v) cout<<i<<" ";
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
        vector<vector<int>> v(n,vector<int>(m));
        for(int k=0;k<n;k++){
            vector<int> f(m,1);
            for(int i=k;i<n;i++){
                for(int j=0;j<m;j++){
                    if(f[j] && grid[i][j]=='1') v[k][j]++;
                    else f[j]=0;
                }
            }
        }
        for(int k=0;k<n;k++){
            res=max(res,rec(v[k]));
        }
        return res;
    }
};