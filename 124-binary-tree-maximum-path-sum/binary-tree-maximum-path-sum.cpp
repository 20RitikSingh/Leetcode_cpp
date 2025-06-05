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
    int rec(TreeNode* root,int sum=0){
        if(!root) return 0;
        int l=rec(root->left,sum+root->val),r=rec(root->right,sum+root->val);
        res=max(res,root->val);
        res=max(res,l+sum+root->val);
        res=max(res,l+r+root->val);
        res=max(res,r+sum+root->val);
        res=max(res,max(root->val,max(l+root->val,r+root->val)));
        // cout<<root->val<<" "<<max(root->val,max(l+root->val,r+root->val))<<endl;;
        return max(root->val,max(l+root->val,r+root->val));
    }
public:
    int maxPathSum(TreeNode* root,int sum=0) {
        rec(root);
        return res;
    }
};