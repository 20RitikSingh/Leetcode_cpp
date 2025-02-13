class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> set;
        for(int i:nums){
            set.insert(i);
        }
        int c=0;
        while(set.size()>1){
            if(*set.begin()>=k) break;
            auto a=set.begin();
            long long t=*a;
            set.erase(a);
            auto b=set.begin();
            // cout<<t<<" "<<*b<<endl;
            set.insert(t+*b+min(t,*b));
            set.erase(b);
            c++;
        }
        return c;
    }
};