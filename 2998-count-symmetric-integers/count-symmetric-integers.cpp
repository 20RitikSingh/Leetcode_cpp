class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++){
            int sum=0;
            string s=to_string(i);
            if(s.size()%2) continue;
            for(int j=0;j<s.size()/2;j++){
                sum+=s[j]-s[s.size()-1-j];
            }
            if(sum==0) c++;
        }
        return c;
    }
};