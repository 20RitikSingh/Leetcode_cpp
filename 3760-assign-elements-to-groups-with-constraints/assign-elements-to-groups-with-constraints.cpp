class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        vector<int> v(100001, 100001) ;
        for(int i=0;i<elements.size();i++) v[elements[i]] = min(v[elements[i]],i) ;
        int n = groups.size(); vector<int> ans(n,100001) ;
        for(int i=0;i<groups.size();i++){
            for(int j=1;j<319;j++){
                if(groups[i]%j == 0){
                    int a = j;  int b = groups[i]/a;
                    ans[i] = min({ans[i],v[a],v[b]}) ;
                }
            }
        }   
        for(int i=0;i<n;i++) if(ans[i] == 100001) ans[i] = -1 ; return ans ;
    }
};