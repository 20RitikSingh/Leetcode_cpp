class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> prev(n,-1),nxt(n,n);
        vector<set<pair<int,int>>> v(1e5+1);
        for(int i=0;i<n;i++){
            while(st.size() && nums[st.top()]>=nums[i]) st.pop();
            if(st.size()) prev[i]=st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int j=n-1;j>=0;j--){
            while(st.size() && nums[st.top()]>=nums[j]) st.pop();
            if(st.size()) nxt[j]=st.top();
            st.push(j);
            v[nums[j]].insert({prev[j],nxt[j]});
        }
        int res=0;
        for(int i=1;i<=1e5;i++){
            res+=v[i].size();
        }
        return res;
    }
};