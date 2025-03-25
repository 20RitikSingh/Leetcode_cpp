class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int c = 0;
        vector<vector<int>> v={{0,0}};
        sort(meetings.begin(), meetings.end());
        for (auto m : meetings) {
            if (v.back()[1] < m[0]) {
                c+=m[0]-1-v.back()[1];
                v[0]=m;
            } else
                v.back()[1] = max(v.back()[1], m[1]);
        }
        c+=days-v.back()[1];
        return c;
    }
};
