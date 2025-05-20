class Solution {
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        vector<int> nxt(m, n); 

        for (int k = n - 1; k >= 0; k--) {
            vector<int> v(m);
            stack<int> st;
            vector<int> prevmin(m, -1);
            for (int j = 0; j < m; j++) {
                if (grid[k][j] == '0') nxt[j] = k;
                v[j] = nxt[j] - k;
                while (!st.empty() && v[st.top()] >= v[j]) st.pop();
                if (!st.empty()) prevmin[j] = st.top();
                st.push(j);
            }
            st=stack<int>(); 
            for (int i = m - 1, nxtmin = m; i >= 0; i--) {
                while (!st.empty() && v[st.top()] >= v[i]) st.pop();
                if (!st.empty()) nxtmin = st.top();
                res = max(res, (nxtmin - prevmin[i] - 1) * v[i]);
                st.push(i);
            }
        }

        return res;
    }
};
