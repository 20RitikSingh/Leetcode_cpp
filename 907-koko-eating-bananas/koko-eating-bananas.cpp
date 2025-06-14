class Solution {
    int check(vector<int> &nums,int h,int k){
        for(int i:nums){
            h-=i/k+(i%k>0);
        }
        return h>=0;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=1e9;
        while(low<high){
            int mid=low+(high-low)/2;
            if(check(piles,h,mid)) high=mid;
            else low=mid+1;
        }
        return low;
    }
};