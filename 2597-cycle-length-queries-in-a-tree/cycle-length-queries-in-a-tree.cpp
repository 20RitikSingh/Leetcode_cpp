class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto& q : queries) {
            int count = 0;
            while (q[0] != q[1]) {
                if (q[0] > q[1]) q[0] /= 2;
                else q[1] /= 2;
                count++;
            }
            res.push_back(count+1);
        }
        return res;
    }
};
