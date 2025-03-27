class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size(),curr=nums[0],c=0,k=0;
        unordered_map<int,int> fq;
        for(int i=0;i<n;i++){
            fq[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(fq[nums[i]]*2>n) k++;
            if(k>(i+1)/2 && fq[nums[i]]-k>(n-1-i)/2) return i;
        }
        return -1;
    }
};