class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res=0,n=nums1.size();
        unordered_map<int,int> f1,f2,f3,f4,f5;
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // sort(nums3.begin(),nums3.end());
        // sort(nums4.begin(),nums4.end());
        // for(int i=0;i<n;i++){
        //     f1[nums1[i]]++;
        //     f2[nums2[i]]++;
        //     f3[nums3[i]]++;
        //     f4[nums4[i]]++;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                f5[nums1[i]+nums2[j]]++;
                // while(j<n-1 && nums2[j]==nums2[j+1]) j++;
            }
            // while(i<n-1 && nums1[i]==nums1[i+1]) i++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                res+=f5[0-nums3[i]-nums4[j]];
                // while(j<n-1 && nums4[j]==nums4[j+1]) j++;
            }
            // while(i<n-1 && nums3[i]==nums3[i+1]) i++;
        }
        return res;
    }
};