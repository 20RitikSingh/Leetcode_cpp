class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0,high=height.size()-1,res=(high-low)*min(height[high],height[low]);
        while(low<high){
            while(low<high && height[low]<=height[high]){
                res=max(res,(high-low)*min(height[high],height[low]));
                low++;
            }
            while(low<high && height[high]<height[low]){
                res=max(res,(high-low)*min(height[high],height[low]));
                high--;
            }

        }
        return res;
    }
};