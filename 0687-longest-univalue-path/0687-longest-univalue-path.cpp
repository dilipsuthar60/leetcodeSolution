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
    int ans=0;
    int find(TreeNode*root,int parent)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=find(root->left,root->val);
        int right=find(root->right,root->val);
        ans=max(ans,left+right);
        return (root->val==parent)?max(left,right)+1:0;
    }
    int longestUnivaluePath(TreeNode* root) 
    {
        find(root,-1);
        return ans;
    }
};