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
    void find(TreeNode*root,vector<int>&nums){
        if(!root) return ;
        find(root->left,nums);
        nums.push_back(root->val);
        find(root->right,nums);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>nums;
        find(root,nums);
        vector<vector<int>>ans;
        for(auto val:queries){
            int min_value=-1;
            int max_value=-1;
            int l=0;
            int r=nums.size()-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(nums[mid]==val){
                    min_value=max_value=val;
                    break;
                }
                if(nums[mid]<val){
                    min_value=nums[mid];
                    l=mid+1;
                }
                else{
                    max_value=nums[mid];
                    r=mid-1;
                }
            }
            ans.push_back({min_value,max_value});
        }
        return ans;
    }
};