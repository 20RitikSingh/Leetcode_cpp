/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // f: 0:not obs 1:obs 2:cam
    unordered_map<TreeNode*,unordered_map<int,int>> dp;
    int rec(TreeNode* root,int f){
        if(!root) return f>1?1e9:0;
        int res=1e9;
        if(dp[root].count(f)) return dp[root][f];
        if(f==0){
            res=min(res,rec(root->left,1)+rec(root->right,1)+1); // self cam
            res=min(res,rec(root->left,2)+rec(root->right,0)+1); // left cam
            res=min(res,rec(root->left,0)+rec(root->right,2)+1); // right cam
            // res=min(res,rec(root->left,2)+rec(root->right,2)+2); // both cam
        }
        if(f==1){
            res=min(res,rec(root->left,1)+rec(root->right,1)+1); // self cam
            // res=min(res,rec(root->left,2)+rec(root->right,0)+1); // left cam
            // res=min(res,rec(root->left,0)+rec(root->right,2)+1); // right cam
            // res=min(res,rec(root->left,2)+rec(root->right,2)+2); // both cam
            res=min(res,rec(root->left,0)+rec(root->right,0)+0); // no cam
        }
        if(f==2){
            // res=min(res,rec(root->left,1)+rec(root->right,1)+1); // self cam
            // res=min(res,rec(root->left,2)+rec(root->right,1)+1); // left cam
            // res=min(res,rec(root->left,1)+rec(root->right,2)+1); // right cam
            // res=min(res,rec(root->left,2)+rec(root->right,2)+2); // both cam
            res=min(res,rec(root->left,1)+rec(root->right,1)+0); // no cam
        }
        dp[root][f]=res;
        return res;
    }
public:
    int minCameraCover(TreeNode* root) {
        return rec(root,0);
    }
};