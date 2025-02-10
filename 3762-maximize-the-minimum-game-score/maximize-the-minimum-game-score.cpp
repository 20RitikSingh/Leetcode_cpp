class Solution {
    bool check(vector<int> &points,long long m,long long mi){
        int n=points.size();
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            v[i]=mi/points[i];
            if(mi%points[i]) v[i]++;
        }
        int last=-1;
        // for(int i:v) cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<n;i++){
            if(v[i]>0){
                m-=i-last-1;
                m-=2*v[i]-1;
                if(i<n-1) v[i+1]-=v[i]-1;
                last=i;
            }
        }
        return m>=0;
    }
public:
    long long maxScore(vector<int>& points, int m) {
        if(points.size()>m) return 0;
        long long low=0,high=*max_element(points.begin(),points.end()),ans=0;
        high*=m;
        // for(int i=0;i<10;i++) cout<<i<<" : "<<(bool)check(points,m,i)<<endl;
        while(low<high){
            long long mid=low+(high-low)/2;
            if(check(points,m,mid)){
                low=mid+1;
            }else high=mid-1;
        }
        if(check(points,m,low)) return low;
        return low-1;
    }
};