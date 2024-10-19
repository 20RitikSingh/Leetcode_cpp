class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int t=pow(2,n)-1;
        if(k==(t+1)/2) return '1';
        if(k>(t+1)/2){
            k-=(t+1)/2;
            char ch=findKthBit(n-1,pow(2,n-1)-k);
            // cout<<n-1<<" "<<pow(2,n-1)-k<<" not:"<<ch<<endl;
            if(ch=='0') return '1';
            return '0'; 
        }
        char ch=findKthBit(n-1,k);
        // cout<<n-1<<" "<<k<<" "<<ch<<endl;
        return ch;
    }
};
// 1 3 7 15 31 63
//  2 4 8 16 32