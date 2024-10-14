class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        priority_queue<int> pq;
        for(int i=0;i<min(k,(int)nums.size());i++)  q.push(nums[i]);
        for(int i=k;i<nums.size();i++){
            if(nums[i]<=q.top()) continue;
            q.pop();
            q.push(nums[i]);
        }
        while(!q.empty()){
            pq.push(q.top());
            q.pop();
        }
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=pq.top();
            if(pq.top()%3) pq.push(pq.top()/3+1);
            else pq.push(pq.top()/3);
            pq.pop();
        }
        return sum;
    }
};