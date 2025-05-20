class Solution {
public:
    int maximalRectangle(vector<vector<char>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        vector<int> nxt(m, n); 
        vector<int> v(m), prevmin(m);
        stack<int> st;

        for (int k = n - 1; k >= 0; k--) {
            // Compute heights and previous smaller in one pass
            st = stack<int>();  // Clear stack
            for (int j = 0; j < m; j++) {
                if (grid[k][j] == '0') nxt[j] = k;
                v[j] = nxt[j] - k;

                while (!st.empty() && v[st.top()] >= v[j]) st.pop();
                prevmin[j] = st.empty() ? -1 : st.top();
                st.push(j);
            }

            // Compute next smaller and max area
            st = stack<int>();  // Clear stack
            for (int j = m - 1, nxtmin = m; j >= 0; j--) {
                while (!st.empty() && v[st.top()] >= v[j]) st.pop();
                nxtmin = st.empty() ? m : st.top();
                res = max(res, (nxtmin - prevmin[j] - 1) * v[j]);
                st.push(j);
            }
        }

        return res;
    }
};
