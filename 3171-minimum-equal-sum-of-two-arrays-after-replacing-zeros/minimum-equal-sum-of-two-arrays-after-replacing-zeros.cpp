class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int nz1=0,nz2=0;
        long long s1=0,s2=0;
        for(int i:nums1){
            if(!i){
                s1++;
                nz1++;
            }
            s1+=i;
        }
        for(int i:nums2){
            if(!i){
                s2++;
                nz2++;
            }
            s2+=i;
        }
        if(s1>s2){
            if(nz2==0) return -1;
            return s1;
        }else if(s2>s1){
            if(nz1==0) return -1;
            return s2;
        }
        return s1;
    }
};