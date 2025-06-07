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
    bool checkBST(TreeNode* root,long long low,long long high){
        if(!root) return 1;
        if(root->val<=low || root->val>=high) return 0;
        if(checkBST(root->left,low,root->val)==0 || checkBST(root->right,root->val,high)==0) return 0;
        return 1;
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root,-1e11,1e11);
    }
};