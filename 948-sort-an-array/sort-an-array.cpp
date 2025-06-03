class Solution {
    void mergesort(vector<int> &nums,int low,int high){
        if(high-low==1) return;
        int mid=low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid,high);
        vector<int> tmp(high-low);
        int i=low,j=mid,k=0;
        while(k<high-low){
            if(i<mid &&(j==high || nums[i]<nums[j])) tmp[k++]=nums[i++];
            else tmp[k++]=nums[j++];
        }
        for(int i=low;i<high;i++){
            nums[i]=tmp[i-low];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size());
        return nums;
    }
};