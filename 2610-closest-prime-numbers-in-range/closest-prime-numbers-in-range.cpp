#define MAXNUM 1000001
bool composite[MAXNUM];
vector<int> prime;
void init(){
    composite[0]=1;
    composite[1]=1;
    for(int i=2;i<MAXNUM;i++){
        if(composite[i]) continue;
        prime.push_back(i);
        for(int j=i;1ll*i*j<MAXNUM;j++){
            composite[i*j]=1;
        }
    }
}
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(!composite[0]) init();
        auto it1=lower_bound(prime.begin(),prime.end(),left);
        auto it2=upper_bound(prime.begin(),prime.end(),right)-1;
        if(it2-it1<1) return {-1,-1};
        for(auto it=it1;it<it2;it++) if(*(it1+1)-*it1>*(it+1)-*it) it1=it;
        return {*it1,*(it1+1)};
    }
};