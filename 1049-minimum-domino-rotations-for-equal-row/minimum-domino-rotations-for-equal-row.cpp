class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size(),mi=1e9;
        for(int k=1;k<7;k++){
            bool f=1;
            int c=0;
            for(int i=0;i<n;i++){
                if(tops[i]==k) continue;
                if(bottoms[i]==k){ c++; continue;}
                f=0;
                break;
            }
            if(f) mi=min(mi,c);
            f=1;
            c=0;
            for(int i=0;i<n;i++){
                if(bottoms[i]==k) continue;
                if(tops[i]==k){ c++; continue;}
                f=0;
                break;
            }
            if(f) mi=min(mi,c);
        }
        if(mi==1e9) return -1;
        return mi;
    }
};