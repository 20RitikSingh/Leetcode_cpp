class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            bool a = 0, b = 0, c = 0;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == 'a')
                    a = 1;
                if (s[j] == 'b')
                    b = 1;
                if (s[j] == 'c')
                    c = 1;
                // if(v[j][a][b][c]>-1) return v[j][a][b][c];
                if (a & b & c) {
                    res += s.size() - j;
                    break;
                }
            }
        }

        return res;
    }
};