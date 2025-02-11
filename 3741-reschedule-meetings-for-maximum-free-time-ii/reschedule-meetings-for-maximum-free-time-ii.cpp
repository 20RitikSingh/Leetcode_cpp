class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> v;
        int n=startTime.size();
        int e=0;
        for(int i=0;i<n;i++){
            v.push_back(startTime[i]-e);
            e=endTime[i];
            // cout<<v.back()<<" ";
        }
        v.push_back(eventTime-e);
        // for(int i:v) cout<<i<<" ";
        vector<int> u=v;
        sort(u.begin(),u.end());
        int mx=u.back();
        for(int i=0;i<n;i++) mx=max(mx,v[i]+v[i+1]);
        for(int i=0;i<n;i++){
            int t=endTime[i]-startTime[i];
            auto it=lower_bound(u.begin(),u.end(),t);
            // cout<<endl<<u.end()-it;
            if(u.end()-it>2){
                mx=max(mx,v[i]+v[i+1]+t);
            }else if(u.end()-it==2){
                mx=max(mx,v[i]+v[i+1]);
                if(min(v[i],v[i+1])==*it && max(v[i],v[i+1])==u.back()) continue;
                mx=max(mx,v[i]+v[i+1]+t);
            }else if(u.end()-it==1){
                if(u.back()!=v[i]&& u.back()!=v[i+1])
                    mx=max(mx,v[i]+v[i+1]+t);
            }
        }
        // reverse(v.begin(),v.end());
        // reverse(startTime.begin(),startTime.end());
        // reverse(endTime.begin(),endTime.end());
        // for(int i=0;i<n;i++){
        //     int t=endTime[i]-startTime[i];
        //     auto it=lower_bound(u.begin(),u.end(),t);
        //     cout<<endl<<u.end()-it;
        //     if(u.end()-it>2){
        //         mx=max(mx,v[i]+v[i+1]+t);
        //     }else if(u.end()-it==2){
        //         mx=max(mx,v[i]+v[i+1]);
        //         if(*it!=v[i] && *it!=v[i+1]) mx=max(mx,v[i]+v[i+1]+t);
        //     }
        // }
        return mx;
    }
};
