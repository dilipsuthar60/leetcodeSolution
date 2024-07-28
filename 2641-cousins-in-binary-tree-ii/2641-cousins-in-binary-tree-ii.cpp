class Solution {
public:
    int mp[100005];
    void dfs(TreeNode* root,int level=1){
        if(root==NULL) return;
        mp[level]+=root->val;
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        memset(mp,0,sizeof(mp));
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