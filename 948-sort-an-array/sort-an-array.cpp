class Solution {
    void mergesort(vector<int> &nums,int low,int high){
        if(high-low==1) return;
        int mid=low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid,high);
        inplace_merge(nums.begin()+low,nums.begin()+mid,nums.begin()+high);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size());
        return nums;
    }
};