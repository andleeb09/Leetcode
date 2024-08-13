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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> treeValues;
        inOrder(root, treeValues);
        return treeValues[k-1]; 
    }
    private:
    void inOrder(TreeNode* node, vector<int>& values){
        if(node==nullptr) return;
        inOrder(node->left,values);
        values.push_back(node->val);
        inOrder(node->right, values); 
    }
};
