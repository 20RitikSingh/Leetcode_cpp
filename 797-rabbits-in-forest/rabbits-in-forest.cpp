class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int v[1001];
        int res=0,n=answers.size();
        for(int i:answers){ 
            res-=v[i]+(i+1-v[i]%(i+1))%(i+1);
            v[i]++;
            res+=v[i]+(i+1-v[i]%(i+1))%(i+1);
        }
        return res;
    }
};