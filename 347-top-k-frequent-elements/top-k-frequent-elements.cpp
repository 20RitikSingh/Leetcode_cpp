class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fm;
        vector<int> res;
        for(auto i:nums) fm[i]++;
        while(fm.size()>k){
            for (auto it = fm.begin(); it != fm.end(); ) {
                it->second--;
                if (it->second == 0) {
                    it = fm.erase(it); 
                } else {
                    ++it; 
                }
            }
        }
        for(auto [key,v]:fm) res.push_back(key);
        return res;
    }
};