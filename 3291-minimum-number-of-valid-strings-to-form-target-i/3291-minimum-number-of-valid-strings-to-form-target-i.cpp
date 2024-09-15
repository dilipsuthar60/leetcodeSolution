class Node{
    public:
        Node*child[26]={NULL};
};
class Trie{
    public:
    Node*root;
    Trie(){
        root=new Node();
    }
    void insert(const string &word){
        Node*current=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(current->child[index]==NULL){
                current->child[index]=new Node();
            }
            current=current->child[index];
        }
    }
};
class Solution {
public:
    int dp[5005];
    int find(const string &s,int index,Node* &root){
        if(index>=s.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans=1e8;
        Node*current=root;
        for(int i=index;i<s.size();i++){
            int curr=s[i]-'a';
            if(current->child[curr]==NULL) break;
            ans=min(ans,1+find(s,i+1,root));
            current=current->child[curr];
        }
        return dp[index] = ans;
    }
    int minValidStrings(vector<string>& words, string target) {
        memset(dp,-1,sizeof(dp));
        Trie trie;
        for(auto &word:words){
            trie.insert(word);
        }
        int value=find(target,0,trie.root);
        if(value>=1e8) return -1;
        return value;
    }
};