class Solution {
public:
    class node{
        public:
        node*child[26]={NULL};
        pair<int,int>pt ={1e6,1e6};
    };
    node*root;
    void insert(string&s,int postion)
    {
        node*current=root;
        int len=s.size();
        current->pt=min(current->pt,{len,postion});
        for(int i=len-1;i>=0;i--)
        {
            int index=s[i]-'a';
            if(current->child[index]==NULL)
            {
                current->child[index]=new node();
            }
            current=current->child[index];
            current->pt=min(current->pt,{len,postion});
        }
    }
    int find(string&s)
    {
        int n=s.size();
        node*current=root;
        for(int i=n-1;i>=0;i--)
        {
            int index=s[i]-'a';
            if(current->child[index]==NULL)
            {
                return current->pt.second;
            }
            current=current->child[index];
        }
        return current->pt.second;;
    }
    vector<int> stringIndices(vector<string>&word, vector<string>&query) 
    {
        root=new node();
        for(int i=0;i<word.size();i++)
        {
            insert(word[i],i);
        }
        vector<int>result;
        for(int i=0;i<query.size();i++)
        {
            result.push_back(find(query[i]));
        }
        return result;
    }
};