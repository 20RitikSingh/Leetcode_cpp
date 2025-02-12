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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        if(root) q.push(root);
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n-1;i++){ 
                if(q.front()->left) q.push(q.front()->left); 
                if(q.front()->right) q.push(q.front()->right); 
                q.pop();
            }
            v.push_back(q.front()->val);
            if(q.front()->left) q.push(q.front()->left); 
            if(q.front()->right) q.push(q.front()->right); 
            q.pop();
        }
        return v;
    }
};