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
    void rec(TreeNode* root,vector<int>& pre, vector<int>& post,int &i,int &j){
        if(j>=pre.size()) return;
        if(post[j]==root->val){
            j++;
            return;
        }
        if(i>=pre.size()) return;
        root->left=new TreeNode(pre[i++]);
        rec(root->left,pre,post,i,j);
        if(j>=pre.size()) return;
        if(post[j]==root->val){
            j++;
            return;
        }
        if(i>=pre.size()) return;
        root->right=new TreeNode(pre[i++]);
        rec(root->right,pre,post,i,j);
        if(j>=pre.size()) return;
        if(post[j]==root->val){
            j++;
            return;
        }
        return;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int i=0,j=0;
        TreeNode* root= new TreeNode(preorder[i++]);
        rec(root,preorder,postorder,i,j);
        return root;
    }
};