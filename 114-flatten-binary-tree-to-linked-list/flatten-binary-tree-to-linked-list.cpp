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
    TreeNode* rec(TreeNode* root){
        if(!root) return root;
        auto leftend=rec(root->left);
        auto rightend=rec(root->right);
        if(leftend){
            leftend->right=root->right;
            root->right=root->left;
            root->left=NULL;
            if(rightend) return rightend;
            return leftend;
        }
        if(rightend) return rightend;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        rec(root);
    }
};