class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n;i++){
            string t=s;
            for(char &j:t){
                if(j=='0') j++;
                else j--;
            }
            reverse(t.begin(),t.end());
            s=s+"1"+t;
        }
        return s[k-1];
    }
};
// 1 3 9 27 81