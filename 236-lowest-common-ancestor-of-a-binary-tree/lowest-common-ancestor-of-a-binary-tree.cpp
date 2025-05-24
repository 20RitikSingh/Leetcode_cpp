/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        int x=(root==p || root==q);
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        if(l==p || l==q) x++;
        else if(l) return l; 
        TreeNode* r=lowestCommonAncestor(root->right,p,q);
        if(r==p || r==q) x++;
        else if(r) return r;
        if(x==2) return root;
        if(!x) return NULL;
        if(l) return l;
        if(r) return r;
        return root;
    }
};