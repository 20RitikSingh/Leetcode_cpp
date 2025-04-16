class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int f=1,b=0,n=nums.size(),c=0,p=0;
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
            v.push_back({b-1,f-1});
            // cout<<b-1<<" "<<f-1<<endl;
        }
        for(int i=0;i<v.size();i++){
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            res+=1LL*(v[i].first-((i==0)?-1:v[i-1].first))*(n-v[i].second);
        }
        return res;
    }
};