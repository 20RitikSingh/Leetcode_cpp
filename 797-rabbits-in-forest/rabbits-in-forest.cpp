class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> v(1001);
        int res=0;
        for(int i:answers) v[i]++;
        for(int i=1;i<1001;i++){
            if(v[i]){ 
                res+=(i+1)*(v[i]/(i+1));
                if(v[i]%(i+1)) res+=i+1;
            }
        }
        return res+v[0];
    }
};