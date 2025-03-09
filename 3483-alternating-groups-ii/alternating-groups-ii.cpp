class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size(),res=0,c=1;
        for(int i=1;i<n+k-1;i++){
            if(colors[i%n]!=colors[(i-1+n)%n]) c++;
            else c=1;
            if(c>=k) res++;
        }
        return res;
    }
};