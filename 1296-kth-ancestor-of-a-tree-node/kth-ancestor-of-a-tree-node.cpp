class TreeAncestor {
    vector<int> prev;
    int dp[50001][20];
    int get(int node,int k){
        // cout<<node<<" "<<k<<endl;
        if(node<0) return -1;
        if(k==0) return prev[node];
        if(dp[node][k]>0) return dp[node][k];
        dp[node][k]=get(get(node,k-1),k-1);
        return dp[node][k];
    }
public:
    TreeAncestor(int n, vector<int>& parent) {
        prev=parent;
    }
    int getKthAncestor(int node, int k) {
        int i=0;
        while(k>=(1<<i)){
            if((1<<i)&k) node=get(node,i);
            // cout<<node<<endl;
            i++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */