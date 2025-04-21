class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mx=0,mi=0,x=0;
        for(int i:differences){ 
            // cout<<x+i<<" ";
            mx=max(mx,x+i);
            mi=min(mi,x+i); 
            x+=i;
        }
        // cout<<endl<<upper-mx<<" "<<mi-lower;
        return max(1LL*0,upper-mx+mi-lower+1);
    }
};