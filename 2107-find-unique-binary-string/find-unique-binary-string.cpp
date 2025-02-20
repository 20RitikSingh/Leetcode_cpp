class Solution {
    string numtostr(int n,int sz){
        string s(sz,'0');
        for(int i=0;i<sz;i++){
            if(n%2) s[i]++;
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> set;
        int n=nums[0].size();
        int i=0;
        while(i<pow(2,n)){
            set.insert(numtostr(i++,n));
        }
        for(auto str:nums){
            set.erase(str);
        }
        return *set.begin();
    }
};