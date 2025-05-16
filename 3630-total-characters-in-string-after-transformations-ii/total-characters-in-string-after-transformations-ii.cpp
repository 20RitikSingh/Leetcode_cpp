class Solution {
    int mod=1e9+7;
    vector<vector<int>> matPow(vector<vector<int>> &x,int p){
        if(x.size()!=x[0].size()) return {{}};
        if(p==1) return x;
        vector<vector<int>> tmp=matPow(x,p/2);
        tmp=matMul(tmp,tmp);
        if(p%2) tmp=matMul(tmp,x);
        return tmp;
    }
    vector<vector<int>> matMul(vector<vector<int>> &x,vector<vector<int>> &y){
        int mx=x.size(),nx=x[0].size(),my=y.size(),ny=y[0].size();
        if(nx!=my) return {{}};
        vector<vector<int>> res(mx,vector<int>(ny));
        for(int i=0;i<mx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nx;k++){
                    res[i][j]=(res[i][j]+1LL*x[i][k]*y[k][j])%mod;
                }
            }
        }
        return res;
    }
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<int>> dp,mat(26,vector<int>(26)),tmp(26,vector<int>(26)),fq(26,vector<int>(1));
        for(char ch:s) fq[ch-'a'][0]++;
        for(int j=0;j<26;j++){
            tmp[j][j]=1;
            for(int k=j+1;k<=j+nums[j];k++){
                mat[k%26][j]=1;
            }
        }
        tmp=matPow(mat,t);
        dp=matMul(tmp,fq);
        int res=0;
        for(int i=0;i<26;i++) res=(0LL+res+dp[i][0])%mod;
        return res;
    }
};