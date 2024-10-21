class Solution {
    struct hash_unordered_set {
    std::size_t operator()(const std::unordered_set<std::string>& s) const {
        std::size_t seed = 0;
        std::hash<std::string> hasher;
        for (const auto& str : s) {
            seed ^= hasher(str) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

// Custom hash function for pair<int, unordered_set<string>>
struct hash_pair {
    std::size_t operator()(const std::pair<int, std::unordered_set<std::string>>& p) const {
        std::size_t seed = 0;

        // Hash the integer part of the pair
        std::hash<int> int_hasher;
        seed ^= int_hasher(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        // Hash the unordered_set part of the pair using the previously defined hash_unordered_set
        hash_unordered_set set_hasher;
        seed ^= set_hasher(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        return seed;
    }
};
    unordered_set<string> set;
    unordered_map<pair<int,unordered_set<string>>,int,hash_pair> dp;
    int rec(string s,int idx=0){
        int n=s.size(),res=0;
        if(idx==n){
            return set.size();
        }
        if(dp.find({idx,set})!=dp.end()) return dp[{idx,set}];
        for(int i=1;i<=n-idx;i++){
            if(set.count(s.substr(idx,i))) continue;
            set.insert(s.substr(idx,i));
            res=max(res,rec(s,idx+i));
            set.erase(s.substr(idx,i));
        }
        dp[{idx,set}]=res;
        return res;
    }
public:
    int maxUniqueSplit(string s) {
        return rec(s);
    }
};