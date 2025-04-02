class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int,vector<int>,greater<int>> q;
        vector<unordered_set<int>> vis(n);
        if(stones[1]!=1) return 0;
        q.push(1);
        vis[1].insert(1);
        vis[1].insert(2);
        // cout<<n<<endl;
        while(q.size()){
            int curr=q.top();
            // cout<<curr<<" ";
            if(curr==n-1) return 1;
            q.pop();
            for(int i=curr+1;i<n;i++){
                if(vis[curr].count(stones[i]-stones[curr])){ 
                    if(i==n-1) return 1;
                    if(vis[i].empty()) q.push(i); 
                    vis[i].insert(stones[i]-stones[curr]-1);
                    vis[i].insert(stones[i]-stones[curr]);
                    vis[i].insert(stones[i]-stones[curr]+1);
                };
            }
        }
        return 0;
    }
};