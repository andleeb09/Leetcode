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
//WITH RECURSION
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(root==NULL)
           root =new TreeNode(val);
       else if (val<root->val)
       root->left= insertIntoBST(root->left,val);
       else 
       root->right=insertIntoBST(root->right,val);
       return root;    
    }
};

//WITHOUT:USING 2 POINTER
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* node = root;
        TreeNode* prev=NULL;
        while(node){
            if(val<node->val){
                prev=node;
                node=node->left;
            }
            else{
                prev=node;
                node=node->right;
            }
        }
        if(val<prev->val){
            TreeNode* newNode = new TreeNode(val);
            prev->left=newNode;
        }
        else{
            TreeNode* newNode = new TreeNode(val);
            prev->right=newNode;
        }
        return root;
    }
};
