class Solution {
    int msb_pos(int n) {
    if (n == 0) return -1;
    int pos = 0;
    while (n >>= 1) pos++;
    return pos;
}

int lca(int x, int y) {
    int i = msb_pos(x);
    int j = msb_pos(y);
    int c = i + j + 2;
    while (i >= 0 && j >= 0 && ((x >> i) & 1) == ((y >> j) & 1)) {
        c -= 2;
        i--; j--;
    }
    return c + 1;
}

public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto q:queries){
            res.push_back(lca(q[0],q[1]));
        }
        return res;
    }
};