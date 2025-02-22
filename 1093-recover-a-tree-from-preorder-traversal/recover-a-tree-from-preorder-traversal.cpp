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
    void rec(TreeNode* root,string &s,int l){
        //cout<<"at level:"<<l<<" node:"<<root->val<<endl;
        int c=0,i=s.size()-1;
        while(i>=0 && s[i--]=='-') c++;
        //cout<<"first c: "<<c<<endl;
        if(c>l){
            while(s.back()=='-') s.pop_back();
            string t="";
            while(s.size() && s.back()!='-'){
                t.push_back(s.back());
                s.pop_back();
            }
            //cout<<"num is: "<<t<<endl;
            root->left=new TreeNode(stoi(t));
            rec(root->left,s,l+1);
            //cout<<"back to level:"<<l<<" node:"<<root->val<<" string is: "<<s<<endl;
            c=0;
            i=s.size()-1;
            while(i>=0 && s[i--]=='-') c++;
            //cout<<"second c: "<<c<<endl;
            if(c>l){
                while(s.back()=='-') s.pop_back();
                string t="";
                while(s.size() && s.back()!='-'){
                    t.push_back(s.back());
                    s.pop_back();
                }
                //cout<<"num is: "<<t<<endl;
                root->right=new TreeNode(stoi(t));
                rec(root->right,s,l+1);
            }
        }
    }
public:
    TreeNode* recoverFromPreorder(string s) {
        reverse(s.begin(),s.end());
        string t="";
        while(s.size() && s.back()!='-'){
            t.push_back(s.back());
            s.pop_back();
        }
        TreeNode* root=new TreeNode(stoi(t));
        rec(root,s,0);
        return root;
    }
};