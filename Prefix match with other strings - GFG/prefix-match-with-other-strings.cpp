//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class node{
    public:
    node*child[26];
    int count;
    node()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=NULL;
        }
        count=0;
    }
};
class Solution{   
public:
    node*root;
    void insert(string &s)
    {
        node*curr=root;
        for(int i=0;i<s.size();i++)
        {
            int index=s[i]-'a';
            if(curr->child[index]==NULL)
            {
                curr->child[index]=new node();
            }
            curr->child[index]->count++;
            curr=curr->child[index];
        }
    }
    int klengthpref(string arr[], int n, int k, string str){    
        root=new node();
        for(int i=0;i<n;i++)
        {
            insert(arr[i]);
        }
        node*curr=root;
        int ans=0;
        for(int i=0;i<k;i++)
        {
            int index=str[i]-'a';
            if(curr->child[index]==NULL)
            {
                return 0;
            }
            ans=curr->child[index]->count;
            curr=curr->child[index];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends