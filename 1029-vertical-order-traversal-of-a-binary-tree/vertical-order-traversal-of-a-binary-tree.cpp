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
    vector<tuple<int,int,int>> v;
    void dfs(TreeNode* root,int row,int col){
        if(!root) return;
        v.push_back({col,row,root->val});
        dfs(root->left,row+1,col-1);
        dfs(root->right,row+1,col+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        sort(v.begin(),v.end());
        vector<vector<int>> res;
        int prev=1e9;
        for(auto [i,j,k]:v){ 
            if(i!=prev) res.push_back({}),prev=i;
            res.back().push_back(k);
        }
        return res;
    }
};