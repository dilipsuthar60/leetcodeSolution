struct node{
    node *child[2]={NULL};
    int count=0;
};
class Solution {
public:
    node *root=new node();
    int MAXBIT=15;
    void insert(int num){
        node *current=root;
        for(int i=MAXBIT;i>=0;i--){
            int bit=(num&(1<<i))>0?1:0;
            if(current->child[bit]==NULL){
                current->child[bit]=new node();
            }
            current=current->child[bit];
            current->count++;
        }
    }
    int getNodeCount(node*root){
        return (root==NULL)?0:root->count;
    }
    int getPairCount(node*root,int index,int value,int high){
        if(root==NULL) return 0;
        if(index<0){
            return root->count;
        }
        int bitV=(value&(1<<index))>0?1:0;
        int bitH=(high&(1<<index))>0?1:0;
        int ans=0;
        if(bitV==1){
            if(bitH==1){
                ans+= getNodeCount(root->child[1])+getPairCount(root->child[0],index-1,value,high);
            }
            else{
                ans+= getPairCount(root->child[1],index-1,value,high);
            }
        }
        else{
            if(bitH==1){
                ans+= getNodeCount(root->child[0])+getPairCount(root->child[1],index-1,value,high);
            }
            else{
                ans+= getPairCount(root->child[0],index-1,value,high);
            }
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=getPairCount(root,MAXBIT,nums[i],high);
            count-=getPairCount(root,MAXBIT,nums[i],low-1);
            insert(nums[i]);
        }
        return count;
    }
};