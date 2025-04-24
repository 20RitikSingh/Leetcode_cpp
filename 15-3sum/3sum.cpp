class Solution {
    int twoSum(vector<int> &nums,int idx,vector<vector<int>> &res){
        // cout<<nums[idx]<<endl;
        unordered_set<int> set;
        int n=nums.size();
        int i=idx;
        i++;
        for(;i<n;i++){
            // if(i==idx) continue;
            if(set.count(0-nums[i]-nums[idx])){
                res.push_back({nums[idx],nums[i],0-nums[i]-nums[idx]});
                while(i<n-1 && nums[i]==nums[i+1]) i++;
            }
            set.insert(nums[i]);
        }
        return 0;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // for(int i:nums) cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            twoSum(nums,i,res);
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};