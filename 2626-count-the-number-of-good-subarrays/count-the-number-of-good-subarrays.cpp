class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int f=1,b=0,n=nums.size(),c=0,p=0,old=-1;
        vector<pair<int,int>> v;
        long long res=0;
        mp[nums[0]]++;
        while(f<n){
            while(p<k){
                if(f>=n) break;
                p+=mp[nums[f]];
                mp[nums[f]]++;
                f++;
            }
            while(p>=k){
                mp[nums[b]]--;
                p-=mp[nums[b]];
                b++;
            }
            // cout<<b-1<<" "<<f-1<<" "<<old<<endl;
            res+=1LL*(b-1-old)*(n-f+1);
            old=b-1;
        }
        return res;
    }
};