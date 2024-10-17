class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        int n=v.size();
        for(int i=n-1;i>0;i--){
            int x=0;
            for(int j=0;j<i;j++) if(v[x]<v[j]) x=j;
            if(v[x]>v[i]){
                swap(v[i],v[x]);
                while(!v.empty()){
                    num*=10;
                    num+=v.back();
                    v.pop_back();
                }
                return num;
            } 
        }
        // for(int i:v) cout<<i<<" ";
        
        while(!v.empty()){
            num*=10;
            num+=v.back();
            v.pop_back();
        }
        return num;
    }
};