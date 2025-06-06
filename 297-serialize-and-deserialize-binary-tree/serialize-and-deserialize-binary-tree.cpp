/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    TreeNode* dec(string &s,int &idx) {
        if(s[idx]==-127){ 
            idx++;
            return NULL;
        }
        int val=s[idx++];
        val<<=7;
        val|=s[idx++];
        TreeNode* t=new TreeNode(val);
        if(s[idx++]==-126) t->left=dec(s,idx);
        if(s[idx++]==-125) t->right=dec(s,idx);
        return t;
    }
    void cod(TreeNode* root,string &s) {
        if(!root){ 
            s.push_back(-127);
            return;
        }
        s.push_back((root->val)>>7);
        s.push_back(((1<<7)-1)&root->val);
        if(root->left) s.push_back(-126);
        cod(root->left,s);
        if(root->right) s.push_back(-125);
        cod(root->right,s);
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        cod(root,res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return dec(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));