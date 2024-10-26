class Solution {
public:
    int in[200005];
    int out[200005];
    int depth[200005];
    int prefix[200005];
    int suffix[200005];
    int time=1;
    void find(TreeNode* root,int d){
        if(root==NULL) return ;
        depth[time]=d;
        in[root->val]=time++;
        find(root->left,d+1);
        find(root->right,d+1);
        out[root->val]=time++;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        find(root,0);
        for(int i=1;i<200005;i++){
            prefix[i]=max(prefix[i-1],depth[i]);
        }
        for(int i=200003;i>=0;i--){
            suffix[i]=max(suffix[i+1],depth[i]);
        }
        
        vector<int>ans;
        for(auto &query:queries){
            int inTime=in[query];
            int outTime=out[query];
            ans.push_back(max(prefix[inTime-1],suffix[outTime+1]));
        }
        return ans;
    }
};