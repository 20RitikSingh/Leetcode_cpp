class Solution {
    int lca(int x, int y) {
        int count = 0;
        while (x != y) {
            if (x > y) x /= 2;
            else y /= 2;
            count++;
        }
        return count + 1;
    }
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto& q : queries) {
            res.push_back(lca(q[0], q[1]));
        }
        return res;
    }
};
