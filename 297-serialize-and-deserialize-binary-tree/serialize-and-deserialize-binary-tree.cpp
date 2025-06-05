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
    TreeNode* dec(string s,int &idx) {
        // cout<<idx<<endl;
        if(s[idx]=='b'){ 
            idx++;
            return NULL;
        }
        // if(idx>=s.size()) cout<<"err"<<endl;
        int val=s[idx++];
        val<<=7;
        // if(idx>=s.size()) cout<<"err"<<endl;
        val|=s[idx++];
        // cout<<"val:"<<val<<endl;
        TreeNode* t=new TreeNode(val);
        // if(idx>=s.size()) cout<<"err"<<endl;
        if(s[idx++]=='l') t->left=dec(s,idx);
        // if(idx>=s.size()) cout<<"err"<<endl;
        if(s[idx++]=='r') t->right=dec(s,idx);
        return t;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "b";
        string l=serialize(root->left);
        string r=serialize(root->right);
        string res(2,0);
        res[1]=((1<<7)-1)&root->val;
        res[0]=(root->val)>>7;
        if(l!="") res+="l"+l;
        if(r!="") res+="r"+r;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        // cout<<data<<endl;
        return dec(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));