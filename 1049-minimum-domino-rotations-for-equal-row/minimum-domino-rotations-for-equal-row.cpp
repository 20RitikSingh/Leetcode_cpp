class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size(),v[7],tf[7],tb[7],k=0;
        for(int i=0;i<n;i++){
            v[tops[i]]++;
            tf[tops[i]]++;
            tb[bottoms[i]]++;
            if(tops[i]!=bottoms[i]) v[bottoms[i]]++;
            if(v[tops[i]]>v[k]) k=tops[i]; 
            if(v[bottoms[i]]>v[k]) k=bottoms[i];
        }
        return v[k]==n?min(n-tf[k],n-tb[k]):-1;
    }
};