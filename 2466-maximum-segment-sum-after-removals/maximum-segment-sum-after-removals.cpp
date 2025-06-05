class Solution {
    struct DSU{
        vector<int> parent,rank;
        vector<long long> sum;
        DSU(int n,vector<int> &nums){
            parent.resize(n);
            rank.resize(n,1);
            sum.resize(n);
            iota(parent.begin(),parent.end(),0);
            for(int i=0;i<n;i++) sum[i]=nums[i];
        }
        long long add(int x,int y){
            x=anc(x),y=anc(y);
            // cout<<x<<" "<<y<<endl;
            if(x==y) return sum[x];
            if(rank[x]<rank[y]) swap(x,y);
            // cout<<x<<" "<<y<<endl;
            // cout<<sum[x]<<" "<<sum[y]<<endl<<endl;
            rank[x]+=rank[y];
            parent[y]=x;
            sum[x]+=sum[y];
            return sum[x];
        }
        int anc(int x){
            if(parent[x]!=x) parent[x]=anc(parent[x]);
            return parent[x];
        }
    };
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& q) {
        int n=nums.size();
        DSU dsu(n,nums);
        vector<bool> vis(n);
        vector<long long> res(n);
        reverse(q.begin(),q.end());
        for(int i=0;i<n-1;i++){
            long long x=dsu.add(q[i],q[i]);
            if(q[i]>0 && vis[q[i]-1]) x=max(x,dsu.add(q[i],q[i]-1));
            if(q[i]<n-1 && vis[q[i]+1]) x=max(x,dsu.add(q[i],q[i]+1));
            vis[q[i]]=1;
            res[i+1]=max(x,res[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};