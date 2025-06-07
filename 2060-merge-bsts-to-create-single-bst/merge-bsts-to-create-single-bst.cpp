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
    unordered_map<int,TreeNode*> mp,kp;
    bool checkBST(TreeNode* root,int low,int high){
        if(!root) return 1;
        if(root->val<=low || root->val>=high) return 0;
        if(checkBST(root->left,low,root->val)==0 || checkBST(root->right,root->val,high)==0) return 0;
        return 1;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right && kp.count(root->val)){
            root->left=kp[root->val]->left;
            root->right=kp[root->val]->right;
        }
        kp.erase(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for(auto root:trees){
            mp[root->val]=root;
            kp[root->val]=root;
            if(root->left) mp[root->left->val]=root->left;
            if(root->right) mp[root->right->val]=root->right;
        }
        for(auto root:trees){
            if(root->left) mp.erase(root->left->val);
            if(root->right) mp.erase(root->right->val);
        }
        if(mp.size()!=1) return NULL; 
        for(auto [k,root]:mp){
            dfs(root);
            if(checkBST(root,-1e9,1e9) && kp.empty()) return root;
        }
        return NULL;
    }
};