class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res=0,n=nums1.size();
        unordered_map<int,int> f1,f3,f5;
        sort(nums1.begin(),nums1.end());
        sort(nums3.begin(),nums3.end());
        for(int i=0;i<n;i++){
            f1[nums1[i]]++;
            f3[nums3[i]]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                f5[nums1[i]+nums2[j]]+=f1[nums1[i]];
            }
            while(i<n-1 && nums1[i]==nums1[i+1]) i++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res+=f3[nums3[i]] *f5[0-nums3[i]-nums4[j]];
            }
            while(i<n-1 && nums3[i]==nums3[i+1]) i++;
        }
        return res;
    }
};