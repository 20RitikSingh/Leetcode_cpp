class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> set;
        int n=nums1.size();
        priority_queue<int ,vector<int>,greater<int>> pq;
        vector<long long> res(n);
        for(int i=0;i<n;i++){
            set.push_back({nums1[i],i});
        }
        sort(set.begin(),set.end());
        long long sum=0;
        for(int i=0;i<n;i++){
            auto [v,idx]=set[i];
            res[idx]=sum;
            if(i>0 && v==set[i-1].first){
                res[idx]=res[set[i-1].second];
            }
            if(pq.size()<k){
                pq.push(nums2[idx]);
                sum+=nums2[idx];
            }else if(pq.top()<nums2[idx]){
                sum-=pq.top();
                sum+=nums2[idx];
                pq.pop();
                pq.push(nums2[idx]);
            }
        }
        return res;
    }
};