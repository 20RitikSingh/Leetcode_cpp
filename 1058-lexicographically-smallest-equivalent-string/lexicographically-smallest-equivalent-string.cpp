class Solution {
    void dfs(vector<set<int>> &adj,int cur,vector<int> &parent,int start){
        if(parent[cur]!=-1) return;
        parent[cur]=start;
        for(int i:adj[cur]) dfs(adj,i,parent,start);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<set<int>> adj(26);
        for(int i=0;i<s1.size();i++){
            adj[s1[i]-'a'].insert(s2[i]-'a');
            adj[s2[i]-'a'].insert(s1[i]-'a');
        }
        vector<int> parent(26,-1);
        for(int i=0;i<26;i++){
            if(parent[i]==-1) dfs(adj,i,parent,i);
        }
        for(auto &ch:baseStr) ch=parent[ch-'a']+'a';
        return baseStr;
    }
};