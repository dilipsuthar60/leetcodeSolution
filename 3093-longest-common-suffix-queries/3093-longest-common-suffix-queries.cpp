class Solution {
public:
    class node{
        public:
        node*child[26]={NULL};
        pair<int,int>pt ={1e6,1e6};
    };
    node*root;
    void insert(string&s,int position)
    {
        node*current=root;
        int len=s.size();
        current->pt=min(current->pt,{len,position});
        for(auto &it:s)
        {
            int index=it-'a';
            if(current->child[index]==NULL)
            {
                current->child[index]=new node();
            }
            current=current->child[index];
            current->pt=min(current->pt,{len,position});
        }
    }
    int find(string&s)
    {
        int n=s.size();
        node*current=root;
        for(auto &it:s)
        {
            int index=it-'a';
            if(current->child[index]==NULL)
            {
                return current->pt.second;
            }
            current=current->child[index];
        }
        return current->pt.second;;
    }
    vector<int> stringIndices(vector<string>&words, vector<string>&querys) 
    {
        root=new node();
        int index=0;
        for(auto &word:words)
        {
            reverse(word.begin(),word.end());
            insert(word,index++);
        }
        vector<int>result;
        for(auto &query:querys)
        {
            reverse(query.begin(),query.end());
            result.push_back(find(query));
        }
        return result;
    }
};