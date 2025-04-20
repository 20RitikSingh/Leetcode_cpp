struct Solution{
    int numRabbits(vector<int>& answers) {
        int v[1002];
        for(int i:answers) if(!i || ++v[i]%(i+1)==1) v[1001]+=(i+1);
        return v[1001];
    }
};