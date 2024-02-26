class Solution {
public:
    class node{
        public:
        node*child[10]={NULL};
    };
    void insert(node*root,string &s)
    {
        node*current=root;
        for(auto &it:s)
        {
            int index=it-'0';
            if(current->child[index]==NULL)
            {
                current->child[index]=new node();
            }
            current=current->child[index];
        }
    }
    int longestPrefix(node*root,string &s)
    {
        node*current=root;
        int len=0;
        for(auto &it:s)
        {
            int index=it-'0';
            if(current->child[index]==NULL)
            {
                return len;
            }
            len++;
            current=current->child[index];
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        node*head=new node();
        for(auto&it:arr1)
        {
            string s=to_string(it);
            insert(head,s);
        }
        int result=0;
        for(auto &it:arr2)
        {
            string s=to_string(it);
            result=max(result,longestPrefix(head,s));
        }
        return result;
    }
};