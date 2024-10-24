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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,NULL});
        unordered_map<TreeNode*,int> v;
        int sum=0,l=0;
        while(!q.empty()){
            int sz=q.size();
            unordered_map<TreeNode*,int> u;
            int nsum=0;
            l++;
            for(int i=0;i<sz;i++){
                auto [c,p]=q.front();
                q.pop();
                c->val=sum-v[p];
                if(l<3) c->val=0;
                if(c->left){
                    q.push({c->left,c});
                    nsum+=c->left->val;
                    u[c]+=c->left->val;
                }
                if(c->right){
                    q.push({c->right,c});
                    nsum+=c->right->val;
                    u[c]+=c->right->val;
                }
            }
            v=u;
            sum=nsum;
        }
        return root;
    }
};