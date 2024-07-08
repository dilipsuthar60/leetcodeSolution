
class Solution {
public:
    class node{
    public:
    node*children[26]={NULL};
    bool isCompleted;
    long long cost;
    node(){
        this->isCompleted=false;
        this->cost=1e13;
    }
};
    node*root=new node();
    int dp[60000];
    bool yes=false;
    void insert(string &s,int value){
        node*curr=root;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new node();
            }
            curr =curr->children[index];
        }
        curr->isCompleted=true;
        curr->cost=min(curr->cost,1ll*value);
    }
    long long find(node* &root,string &s,int index){
        if(index>=s.size()) {
            yes=true;
            return 0;
        }
        long long ans=1e13;
        node*curr=root;
        if(dp[index]!=-1) return dp[index];
        for(int i=index;i<s.size();i++)
        {
            int currentIndex=s[i]-'a';
            if(curr->children[currentIndex]==NULL){
                break;
            }
            curr=curr->children[currentIndex];
            if(curr->isCompleted){
                ans=min(ans,1ll*curr->cost+find(root,s,i+1));
            }
        }
        return dp[index] = ans;
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        for(int i=0;i<words.size();i++){
            insert(words[i],costs[i]);
        }
        memset(dp,-1,sizeof(dp));
        long long result=find(root,target,0);
        if(yes) return result;
        return -1;
    }
};