class Solution {
public:
    int countLargestGroup(int n) {
        int arr[40],c=0,mx=0;
        for(int i=1;i<=n;i++){
            int x=i,y=0;
            while(x>0){
                y+=x%10;
                x/=10;
            }
            arr[y]++;
            mx=max(mx,arr[y]);
        }
        for(int i:arr) if(mx==i) c++;
        return c;
    }
};