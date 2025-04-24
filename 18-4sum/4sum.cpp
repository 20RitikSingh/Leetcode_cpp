class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int k=0;k<n;k++){
            for(int i=k+1;i<n;i++){
                unordered_set<long long> set;
                for(int j=i+1;j<n;j++){
                    if(set.count(0LL+target-nums[k]-nums[j]-nums[i])){
                        res.push_back({nums[k],nums[i],nums[j],target-nums[k]-nums[j]-nums[i]});
                        while(j<n-1 && nums[j]==nums[j+1]) j++;
                    }
                    set.insert(nums[j]);
                }
                while(i<n-1 && nums[i]==nums[i+1]) i++;
            }
            while(k<n-1 && nums[k]==nums[k+1]) k++;
        }
        return res;
    }
};