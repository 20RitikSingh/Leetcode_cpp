unordered_map<string,int> dp;
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start,end="123450";
        for(auto i:board) for(int j:i) start.push_back(j+'0');
        if(dp.count(start)) return dp[start];
        
        unordered_set<string> vis;
        queue<string> q;
        int steps=0;

        q.push(start);
        vis.insert(start);
        
        while(q.size()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string curr=q.front();
                q.pop();

                if(curr==end){dp[start]=steps; return steps;}

                int pos=0;
                for(int i=0;i<6;i++) if(curr[i]=='0'){ pos=i; break;}

                string s=curr;
                swap(s[pos],s[(3+pos)%6]);
                if(vis.count(s)==0){
                    vis.insert(s);
                    q.push(s);
                }
                
                s=curr;
                if(pos!=0 && pos!=3){
                    swap(s[pos],s[pos-1]);
                    if(vis.count(s)==0){
                        vis.insert(s);
                        q.push(s);
                    }
                }

                s=curr;
                if(pos!=2 && pos!=5){
                    swap(s[pos],s[pos+1]);
                    if(vis.count(s)==0){
                        vis.insert(s);
                        q.push(s);
                    }
                }
            }
            steps++;
        }
        dp[start]=-1;
        return -1;
    }
};