class Solution {
public:
#define MAX 100000
    int maxTotalReward(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        bitset<MAX> can;
        can[0]=1;
        for(int i:nums){
            can=can|(can<<(MAX-i)>>(MAX-i)<<i);
        }
        for(int i=MAX-1;i>=0;i--) if(can[i]) return i;
        return 0;
    }

};
