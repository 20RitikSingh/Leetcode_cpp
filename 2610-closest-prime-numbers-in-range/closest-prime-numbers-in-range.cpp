#define MAXNUM 1000001
bool composite[MAXNUM];
void init(){
    composite[0]=1;
    composite[1]=1;
    for(int i=2;i<MAXNUM;i++){
        if(composite[i]) continue;
        for(int j=i;1ll*i*j<MAXNUM;j++){
            composite[i*j]=1;
        }
    }
}
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(!composite[0]) init();
        vector<int> ans,res;
        int k=0;
        for(int i=left;i<=right;i++){
            if(composite[i]) continue;
            if(ans.size()>1 && ans[k+1]-ans[k]>i-ans.back()) k=ans.size()-1;
            ans.push_back(i);
        }
        cout<<composite[left]<<endl;
        for(int i:ans) cout<<i<<" ";
        if(ans.size()<2)
            return {-1,-1};
        return {ans[k],ans[k+1]};
    }
};