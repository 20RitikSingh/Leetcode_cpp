struct Solution{
    int numRabbits(vector<int>& answers) {
        int16_t v[1001];
        int res=0;
        for(int i:answers) if(!i || ++v[i]%(i+1)==1) res+=(i+1);
        return res;
    }
};