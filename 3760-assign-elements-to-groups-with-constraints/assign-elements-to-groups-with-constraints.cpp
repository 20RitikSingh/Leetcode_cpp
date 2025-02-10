class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n=groups.size(),m=elements.size(),mx=*max_element(groups.begin(),groups.end());
        vector<int> v(mx+1,-1),res(n,-1);
        for(int i=0;i<m;i++){
            for(int j=1;j*elements[i]<mx+1;j++){
                if(v[j*elements[i]]<0){
                    v[j*elements[i]]=i;
                }else if(elements[i]%elements[v[j*elements[i]]]==0) break;
            }
        }
        // for(int i=0;i<mx+1;i++) cout<<i<<" : "<<v[i]<<" , ";
        for(int i=0;i<n;i++){
            res[i]=v[groups[i]];
        }
        return res;
    }
};