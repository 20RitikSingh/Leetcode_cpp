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
class FindElements {
    unordered_set<int> set;
public:
    FindElements(TreeNode* root) {
        int i=0;
        queue<TreeNode*> q;
        root->val=0;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            set.insert(t->val);
            q.pop();
            if(t->left){
                t->left->val=t->val*2+1;
                q.push(t->left);
            }
            if(t->right){
                t->right->val=t->val*2+2;
                q.push(t->right);
            }
        }
    }
    
    bool find(int target) {
        return set.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */