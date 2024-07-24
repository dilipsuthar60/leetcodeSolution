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
    TreeNode*find(TreeNode*root,int sum,int limit){
        if(root==NULL) return NULL;
        if(root->left==NULL&&root->right==NULL){
            return ((root->val+sum)<limit)?NULL:root;
        }
        root->left = find(root->left,sum+root->val,limit);
        root->right = find(root->right,sum+root->val,limit);
        return (!root->left&&!root->right)?NULL:root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return find(root,0,limit);
    }
};