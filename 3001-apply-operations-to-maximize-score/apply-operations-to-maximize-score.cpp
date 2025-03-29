
class Solution {
    int MOD=1000000007;
    long long pow(long long x,long long y){
        if(y==1) return x;
        long long res=pow(x,y/2);
        if(y%2) return (((res*x)%MOD)*res)%MOD;
        return (res*res)%MOD;
    }
    bool comp[100002];
public:
    int maximumScore(vector<int>& nums, int k) {
        comp[1]=1;
        for(int i=2;i<100002;i++){
            if(comp[i]) continue;
            for(int j=i;j<=100002/i;j++){
                comp[i*j]=1;
            }
        }
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i:nums){
            if(mp.find(i)!=mp.end()) continue;
            int x=i;
            for(int j=2;j<=sqrt(i);j++){
                if(i%j) continue;
                if(!comp[j]) mp[i]++;
                if(i/j!=j && !comp[i/j]) mp[i]++;
            }
            if(!comp[i]) mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            // cout<<mp[nums[i]]<<" ";
            pq.push({nums[i],i});
        }
        long long x=1;
        vector<int> lft(n),rgt(n);
        int mx=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && mp[nums[st.top()]]<mp[nums[i]]) st.pop();
            if(st.empty()) lft[i]=i;
            else lft[i]=i-st.top()-1;
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && mp[nums[st.top()]]<=mp[nums[i]]) st.pop();
            if(st.empty()) rgt[i]=n-1-i;
            else rgt[i]=st.top()-i-1;
            st.push(i);
        }
        // cout<<endl;
        // for(int i=0;i<n;i++) cout<<lft[i]<<","<<rgt[i]<<" ";
        while(k){
            auto [val,idx]=pq.top();
            pq.pop();
            int l=lft[idx],r=rgt[idx];
            // for(int i=idx+1;i<n;i++){
            //     if(mp[nums[i]]>mp[val]) break;
            //     r++;
            // }
            // for(int i=idx-1;i>=0;i--){
            //     if(mp[nums[i]]>=mp[val]) break;
            //     l++; 
            // }
            // cout<<l<<","<<r<<" ";
            x*=pow(val,min(1LL*k,1LL*(l+1)*(r+1)));
            k-=min(1LL*k,1LL*(l+1)*(r+1));
            x%=1000000007;
        }
        return x;
    }
};