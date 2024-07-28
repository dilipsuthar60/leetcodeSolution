class Solution {
public:
    vector<int>mp;
    int getHeightOfTree(TreeNode*root){
        if(!root) return 0;
        int left=getHeightOfTree(root->left);
        int right=getHeightOfTree(root->right);
        return max(left,right)+1;
    }
    void dfs(TreeNode* root,int level=1){
        if(root==NULL) return;
        mp[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        int height =getHeightOfTree(root);
        mp=vector<int>(height+2,0);
        dfs(root);
        queue<TreeNode*>q;
        q.push(root);
        root->val=0;
        int level=1;
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto currentNode=q.front();
                q.pop();
                int sum=mp[level+1];
                if(currentNode->left!=NULL){
                    sum-=currentNode->left->val;
                }
                if(currentNode->right!=NULL){
                    sum-=currentNode->right->val;
                }
                if(currentNode->left!=NULL){
                    currentNode->left->val=sum;
                    q.push(currentNode->left);
                }
                if(currentNode->right!=NULL){
                    currentNode->right->val=sum;
                    q.push(currentNode->right);
                }
            }
            level++;
        }
        return root;
    }
};