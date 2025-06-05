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
    int res=-1e9;
    int rec(TreeNode* root){
        if(!root) return 0;
        int l=max(0,rec(root->left)),r=max(0,rec(root->right));
        res=max(res,root->val+l);
        res=max(res,root->val+r);
        res=max(res,root->val+l+r);
        return max(l+root->val,r+root->val);
    }
public:
    int maxPathSum(TreeNode* root,int sum=0) {
        rec(root);
        return res;
    }
};