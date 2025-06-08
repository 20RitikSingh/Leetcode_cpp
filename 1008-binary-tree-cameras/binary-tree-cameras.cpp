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
    int res=0;
    int rec(TreeNode* root){
        if(!root) return 1;
        int l=rec(root->left);
        int r=rec(root->right);
        if(!l || !r){
            res++;
            return 2;
        }
        if(l==2 || r==2) return 1;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(!rec(root)) res++;
        return res;
    }
};