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
    vector<int>ans;
    vector<int> find(TreeNode*root){
        if(root==NULL) return {1,0};
        auto left=find(root->left);
        auto right=find(root->right);
        if(left[0]&&right[0]&&left[1]==right[1]){
            ans.push_back(left[1]+right[1]+1);
            return {1,left[1]+right[1]+1};
        }
        return {0,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        find(root);
        sort(ans.rbegin(),ans.rend());
        if(ans.size()<k) return -1;
        return ans[k-1];
    }
};