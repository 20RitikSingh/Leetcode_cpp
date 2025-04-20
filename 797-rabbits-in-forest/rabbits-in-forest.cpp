class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int v[1001];
        int res=0,n=answers.size();
        for(int i:answers){ 
            // v[i]++;
            if(!i || ++v[i]%(i+1)==1) res+=(i+1);
        }
        return res;
    }
};