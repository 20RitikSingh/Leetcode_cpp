#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_multiset = tree<
    std::pair<T, int>,
    null_type,
    std::greater<std::pair<T, int>>,  // Descending order
    rb_tree_tag,
    tree_order_statistics_node_update>;
class Solution {
public:

int reversePairs(vector<int>& nums) {
    ordered_multiset<long long> set;
    int res = 0, n = nums.size(),uid=0;
    for (int i = 0; i < n; ++i) {
        long long val = 2LL * nums[i];
        // Count number of elements > val
        int count =set.order_of_key({val, INT_MAX});
        res += count;
        set.insert({nums[i],uid++});
    }
    return res;
}

};