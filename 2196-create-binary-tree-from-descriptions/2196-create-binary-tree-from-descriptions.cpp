class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& nums) 
    {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int parent=nums[i][0];
            int child=nums[i][1];
            int isLeft=nums[i][2];
            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if(isLeft){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
            s.insert(child);
        }
        int root=0;
        for(auto it:nums){
            if(s.find(it[0])==s.end()){
                root=it[0];
                break;
            }
        }
        return mp[root];
    }
};