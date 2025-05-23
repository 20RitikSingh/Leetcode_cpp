class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for(auto i:board) for(int j:i) start.push_back(j+'0');
        string end="123450";
        unordered_set<string> vis;
        queue<string> q;
        q.push(start);
        vis.insert(start);
        int steps=0;
        while(q.size()){
            int sz=q.size();
            
            for(int i=0;i<sz;i++){
                string curr=q.front();
                q.pop();

                if(curr==end) return steps;

                int pos=0;
                for(int i=0;i<6;i++) if(curr[i]=='0'){ pos=i; break;}
                // cout<<pos<<endl;
                // cout<<curr<<" ";

                string s=curr;
                swap(s[pos],s[(3+pos)%6]);
                if(vis.count(s)==0){
                    vis.insert(s);
                    q.push(s);
                }
                // cout<<s<<" ";
                
                s=curr;
                if(pos!=0 && pos!=3){
                    swap(s[pos],s[pos-1]);
                    if(vis.count(s)==0){
                        vis.insert(s);
                        q.push(s);
                    }
                }
                // cout<<s<<" ";

                s=curr;
                if(pos!=2 && pos!=5){
                    swap(s[pos],s[pos+1]);
                    if(vis.count(s)==0){
                        vis.insert(s);
                        q.push(s);
                    }
                }
                // cout<<s<<" ";
                // cout<<endl;
            }
            steps++;
        }
        return -1;
    }
};