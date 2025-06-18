class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<20001> can;
        can[0]=1;
        int sum=0;
        for(int i:nums){
            sum+=i;
            for(int j=sum+i;j>=i;j--){
                if(can[j-i]) can[j]=1;
            }
            // cout<<can<<endl;
        }
        if(sum%2) return 0;
        return can[sum/2];
    }
};