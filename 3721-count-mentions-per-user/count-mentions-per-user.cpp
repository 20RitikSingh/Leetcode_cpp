bool cmp(vector<string> e1,vector<string> e2){
    if(stoi(e1[1])<stoi(e2[1])) return 1;
    if(stoi(e1[1])>stoi(e2[1])) return 0;
    if(e1[0]=="OFFLINE") return 1;
    return 0;
}
class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        int ne=events.size();
        vector<int> res(n),online(n,1);;
        queue<pair<int,int>> q;
        sort(events.begin(),events.end(),cmp);
        for(int i=0;i<ne;i++){
            if(events[i][0]=="MESSAGE"){
                int t=stoi(events[i][1]);
                while(!q.empty() && q.front().first<=t){ 
                    online[q.front().second]++;
                    q.pop();
                }
                if(events[i][2]=="ALL"){
                    for(int &j:res) j++;
                }else if(events[i][2]=="HERE"){
                    for(int j=0;j<n;j++){
                        res[j]+=online[j];
                    }
                }else{
                    string s=events[i][2];
                    for(int j=0;j<s.size();j++){
                        if(s[j]=='d'){
                            string k="";
                            j++;
                            while(j<s.size() && s[j]!='i'){
                                k.push_back(s[j]);
                                j++;
                            }
                            res[stoi(k)]++;
                        }
                    }
                }
            }else{
                int id=stoi(events[i][2]);
                online[id]--;
                q.push({stoi(events[i][1])+60,id});
            }
        }
        return res;
    }
};