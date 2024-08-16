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
    int find(TreeNode*root,int &sum)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=find(root->left,sum);
        int right=find(root->right,sum);
        int l=0,r=0;
        if(root->left!=NULL&&root->left->val==root->val)
        {
            l=left+1;
        }
        if(root->right!=NULL&&root->right->val==root->val)
        {
            r=right+1;
        }
        sum=max(sum,l+r);
        return max(l,r);
    }
    int longestUnivaluePath(TreeNode* root) 
    {
        int ans=0;
        find(root,ans);
        return ans;
    }
};