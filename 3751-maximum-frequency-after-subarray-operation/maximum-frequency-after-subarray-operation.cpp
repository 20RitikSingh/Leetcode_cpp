class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        vector<int> v;
        int n=nums.size(),res=0,ck=0;
        for(int i:nums) if(i==k) ck++;
        for(int i=0;i<51;i++){
            int c=0;
            for(int j:nums){
                if(j==i) c++;
                if(j==k) c--;
                c=max(0,c);
                res=max(res,c);
            }
        }
        return res+ck;
    }
};