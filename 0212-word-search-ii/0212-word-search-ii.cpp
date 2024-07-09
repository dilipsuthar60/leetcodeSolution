class Solution {
public:
    struct node
    {
        node *child[26]={NULL};
        int end=0;
        string str="";
    };
    node*root=new node();
    void insert(string &s)
    {
        int n=s.size();
        node*curr=root;
        for(int i=0;i<n;i++)
        {
            int index=s[i]-'a';
            if(curr->child[index]==NULL)
            {
                curr->child[index]=new node();
            }
            curr=curr->child[index];
        }
        curr->end=1;
        curr->str=s;
    }
    void find(vector<vector<char>>&mat,int i,int j,vector<string>&v,node*curr)
    {
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]=='#'||curr->child[mat[i][j]-'a']==NULL)
        {
            return ;
        }
    
            curr=curr->child[mat[i][j]-'a'];
            if(curr->end)
            {
                v.push_back(curr->str);
            }
            char ch=mat[i][j];
            mat[i][j]='#';
        find(mat,i+1,j,v,curr);
        find(mat,i-1,j,v,curr);
        find(mat,i,j+1,v,curr);
        find(mat,i,j-1,v,curr);
            mat[i][j]=ch;
    }
    vector<string> findWords(vector<vector<char>>& mat, vector<string>& words)
    {
        vector<string>v;
        int n=mat.size();
        int m=mat[0].size();
        for(auto &it:words)
        {
            insert(it);
        }
        node*curr=root;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                find(mat,i,j,v,curr);
            }
        }
        unordered_set<string>st(v.begin(),v.end());
        v.clear();
        for(auto &it:st)
        {
            v.push_back(it);
        }
        return v;
    }
};