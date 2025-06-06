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
    tuple<int,int,int> dfs(TreeNode* root){
        int mil=root->val,mxl=root->val,suml=0;
        int mir=root->val,mxr=root->val,sumr=0,f=0;
        if(root->left){
            auto [x,y,z] = dfs(root->left);
            mil=x,mxl=y,suml=z;
            if(mxl>=root->val) f=1;
        }
        if(root->right){
            auto [x,y,z] = dfs(root->right);
            mir=x,mxr=y,sumr=z;
            if(mir<=root->val) f=1;
        }
        if(f) return {-1e9,1e9,0};
        res=max(res,suml+sumr+root->val);
        return {mil,mxr,suml+sumr+root->val};
    }
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return res;
    }
};