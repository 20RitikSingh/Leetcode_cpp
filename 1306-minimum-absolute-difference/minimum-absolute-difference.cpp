class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(),arr.end());
        int k=1e9;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]<k){
                k=arr[i]-arr[i-1];
                res=vector<vector<int>>();
            }
            if(arr[i]-arr[i-1]==k) res.push_back({arr[i-1],arr[i]});
        }
        return res;
    }
};