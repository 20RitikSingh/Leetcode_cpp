
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
            for(int j=2;j<=sqrt(i);j++){
                if(i%j) continue;
                if(!comp[j]) mp[i]++;
                if(i/j!=j && !comp[i/j]) mp[i]++;
            }
            if(!comp[i]) mp[i]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long x=1;
        vector<int> lft(n),rgt(n);
        stack<int> st,st1;
        for(int i=0;i<n;i++){
            int j=n-1-i;
            while(!st.empty() && mp[nums[st.top()]]<mp[nums[i]]) st.pop();
            if(st.empty()) lft[i]=i;
            else lft[i]=i-st.top()-1;
            st.push(i);
            while(!st1.empty() && mp[nums[st1.top()]]<=mp[nums[j]]) st1.pop();
            if(st1.empty()) rgt[j]=n-1-j;
            else rgt[j]=st1.top()-j-1;
            st1.push(j);
        }
        while(k){
            auto [val,idx]=pq.top();
            pq.pop();
            int l=lft[idx],r=rgt[idx];
            x=(x*pow(val,min(1LL*k,1LL*(l+1)*(r+1))))%MOD;
            k-=min(1LL*k,1LL*(l+1)*(r+1));
        }
        return x;
    }
};