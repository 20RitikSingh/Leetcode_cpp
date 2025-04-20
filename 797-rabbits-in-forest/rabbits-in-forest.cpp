class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int v[1001];
        int res=0,n=answers.size();
        for(int i=0;i<n;i++) v[answers[i]]++;
        for(int i=1;i<1001;i++){
            if(v[i]){ 
                res+=v[i]+(i+1-v[i]%(i+1))%(i+1);
            }
        }
        return res+v[0];
    }
};