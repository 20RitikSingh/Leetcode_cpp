class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int low=0,high=1,mx=0,mi=0,res=1,n=nums.size();
        set<pair<int,int>> set;
        priority_queue<pair<int,int>> q;
        set.insert({nums[0],0});
        q.push({nums[0],0});
        while(high<n){
            if(low==high){
                high=low+1;
                q.push({nums[low],low});
                set.insert({nums[low],low});
            }
            while(set.size() && set.begin()->second<low) set.erase(set.begin());
            mi=set.begin()->second;
            while(q.size() && q.top().second<low) q.pop();
            mx=q.top().second;
            cout<<mx<<" "<<mi<<endl;
            while(high<n && nums[mx]-nums[mi]<=limit){
                res=max(res,high-low);
                if(nums[mx]<=nums[high]) mx=high;
                if(nums[mi]>=nums[high]) mi=high;
                q.push({nums[high],high});
                set.insert({nums[high],high});
                mx=max(low,mx);
                mi=max(low,mi);
                cout<<high<<endl;
                high++;
            }
            if(nums[mx]-nums[mi]<=limit) res=max(res,high-low);
            low=min(mi,mx)+1;
            cout<<"low"<<low<<endl;
        }
        return res;
    }
};