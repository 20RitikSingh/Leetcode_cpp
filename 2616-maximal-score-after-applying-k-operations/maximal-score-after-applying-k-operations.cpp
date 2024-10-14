class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        for(int i:nums) q.push(i);
        long long sum=0;
        for(int i=0;i<k;i++){
            sum+=q.top();
            if(q.top()%3) q.push(q.top()/3+1);
            else q.push(q.top()/3);
            q.pop();
        }
        return sum;
    }
};