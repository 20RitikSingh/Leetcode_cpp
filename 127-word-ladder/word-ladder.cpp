class Solution {
    int dist(string s,string t){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]) c++;
        }
        return c;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size(),start=n,end=-1,steps=1;
        vector<vector<int>> adj(n+1);
        vector<bool> vis(n+1);
        queue<int> q;

        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord) start=i;
            if(wordList[i]==endWord) end=i;
            for(int j=i+1;j<n;j++){
                if(dist(wordList[i],wordList[j])!=1) continue;
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }

        if(end==-1) return 0;
        if(start==n)
        for(int j=0;j<n;j++){
            if(dist(beginWord,wordList[j])!=1) continue;
            adj[n].push_back(j);
            adj[j].push_back(n);
        }

        q.push(start);
        vis[start]=1;

        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int cur=q.front();
                q.pop();
                
                if(cur==end) return steps;

                for(int j:adj[cur]){
                    if(vis[j]) continue;
                    q.push(j);
                    vis[j]=1;
                }
            }
            steps++;
        }

        return 0;
    }
};