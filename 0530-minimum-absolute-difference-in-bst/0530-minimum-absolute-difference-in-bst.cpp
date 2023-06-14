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
    TreeNode*prev;
    int ans;
    void find(TreeNode*root)
    {
        if(root==NULL)
        {
            return ;
        }
        find(root->left);
        if(prev!=NULL)
        {
            ans=min(ans,abs(root->val-prev->val));
        }
        prev=root;
        find(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        this->ans=1e9+10;
        prev=NULL;
        find(root);
        return ans;
    }
};