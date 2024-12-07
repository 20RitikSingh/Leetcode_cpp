class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> set;
        int c=0; 
        for(int i:banned) if(i<=n) set.insert(i);
        for(int i=1;i<=n;i++){
            if(set.count(i)) continue;
            if(maxSum<i) return c;
            c++;
            maxSum-=i;
        }
        return c;
    }
};