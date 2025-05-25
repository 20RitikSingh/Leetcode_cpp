class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> prev(n,-1),nxt(n,n);
        int res=0;
        for(int i=0;i<n;i++){
            while(st.size() && nums[st.top()]>=nums[i]) st.pop();
            if(st.size()) prev[i]=st.top();
            st.push(i);
            res=max(res,nums[i]);
        }
        vector<int> last(res+1,n+1);
        res=0;
        st=stack<int>();
        for(int j=n-1;j>=0;j--){
            while(st.size() && nums[st.top()]>=nums[j]) st.pop();
            if(st.size()) nxt[j]=st.top();
            st.push(j);
            if(nums[j] && last[nums[j]]>=nxt[j]){
                res++;
                last[nums[j]]=prev[j];
            }
        }
        return res;
    }
};