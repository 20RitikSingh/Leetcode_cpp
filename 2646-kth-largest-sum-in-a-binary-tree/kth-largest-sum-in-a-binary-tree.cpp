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
#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            ll sum=0;
            for(int i=0;i<sz;i++){
                auto x=q.front();
                sum+=x->val;
                q.pop();
                if(x->right) q.push(x->right);
                if(x->left) q.push(x->left);
            }
            if(pq.size()<k) pq.push(sum);
            else if(pq.top()<sum){ pq.push(sum); pq.pop();}
        }
        if(pq.size()<k) return -1;
        return pq.top();
    }
};