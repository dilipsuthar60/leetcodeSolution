class node{
    public:
    node* children[256]={NULL};
    bool end=false;
    node(){
        this->end=false;
    }
};
class Solution {
public:
    node*root=new node();
    bool insert(string &s){
        node*curr=root;
        for(int i=0;i<s.size();i++){
            int index=s[i];
            if(curr->children[index]==NULL){
                curr->children[index]=new node();
            }
            curr=curr->children[index];
            if(curr->end&&s[i+1]=='/') return false; 
        }
        curr->end=true;
        return true;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>result;
        for(auto &it:folder){
            if(insert(it)){
                result.push_back(it);
            }
        }
        return result;
    }
};