class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        // for(int i:nums) set.insert(i);
        int res=0,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res+=8*mp[nums[i]*nums[j]];
                mp[nums[i]*nums[j]]++;
            }
        }
        return res;
    }
};