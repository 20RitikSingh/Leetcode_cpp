class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size(),curr=nums[0],c=0,k=0;
        for(int i=0;i<n;i++){
            if(curr==nums[i]) c++;
            else c--;
            if(c<=0){
                c=1;
                curr=nums[i];
            }
        }
        c=0;
        for(int i=0;i<n;i++) if(nums[i]==curr) c++;
        // cout<<curr<<endl;
        if(c<=n/2) return -1;
        for(int i=0;i<n;i++){
            if(nums[i]==curr) k++;
            if(k>(i+1)/2 && c-k>(n-1-i)/2) return i;
        }
        return -1;
    }
};