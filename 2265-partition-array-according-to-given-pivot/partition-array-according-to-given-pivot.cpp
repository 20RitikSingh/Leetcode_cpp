class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res,more;
        int c=0;
        for(auto i:nums){
            if(i<pivot) res.push_back(i);
            else if(i==pivot) c++;
            else more.push_back(i);
        }
        while(c--) res.push_back(pivot);
        for(int i:more) res.push_back(i);
        return res;
    }
};