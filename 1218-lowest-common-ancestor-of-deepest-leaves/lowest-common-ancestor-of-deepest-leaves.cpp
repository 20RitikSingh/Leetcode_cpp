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
    pair<TreeNode*,int> rec(TreeNode* root){
        if(!root) return {NULL,0};
        auto l=rec(root->left);
        auto r=rec(root->right);
        // cout<<root->val<<endl;
        // cout<<l.second<<" "<<l.first<<endl;
        if(l.second>r.second) return {l.first,max(l.second,r.second)+1};
        if(r.second>l.second) return {r.first,max(l.second,r.second)+1};
        return {root,max(l.second,r.second)+1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return rec(root).first;
    }
};