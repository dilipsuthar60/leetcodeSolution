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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>levelSum;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            long long currentLevelSum=0;
            for(int i=q.size()-1;i>=0;i--){
                auto temp=q.front();
                q.pop();
                currentLevelSum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            levelSum.push_back(currentLevelSum);
        }
        sort(levelSum.rbegin(),levelSum.rend());
        if(levelSum.size()<k) return -1;
        return levelSum[k-1];
    }
};