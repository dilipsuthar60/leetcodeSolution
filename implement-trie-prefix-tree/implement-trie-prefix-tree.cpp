class node{
    public:
    node* child[26]={NULL};
    bool end = false;
};
class Trie {
public:
    node*root;
    Trie() {
        root=new node();
    }
    int getWordCharIndex(char ch){
        return ch-'a';
    }
    void insert(string word) {
        node*currentNode=root;
        for(auto &ch:word){
            int index=getWordCharIndex(ch);
            if(currentNode->child[index]==NULL){
                currentNode->child[index]=new node();
            }
            currentNode=currentNode->child[index];
        }
        currentNode->end=true;
        return ;
    }
    
    bool search(string word) {
        node*currentNode=root;
        for(auto &ch:word){
            int index=getWordCharIndex(ch);
            if(currentNode->child[index]==NULL){
                return false;
            }
            currentNode=currentNode->child[index];
        }
        return currentNode->end;
    }
    
    bool startsWith(string prefix) {
        node*currentNode=root;
        for(auto &ch:prefix){
            int index=getWordCharIndex(ch);
            if(currentNode->child[index]==NULL){
                return false;
            }
            currentNode=currentNode->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */