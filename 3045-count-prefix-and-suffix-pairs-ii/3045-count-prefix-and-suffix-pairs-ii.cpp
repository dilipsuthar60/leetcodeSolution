class Solution {
public:
    class node{
        public:
          int count=0;
          map<pair<char,char>,node*>child;
    };
    int insert(string &s,node*head)
    {
        node*current=head;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            char first=s[i];
            char last=s[s.size()-i-1];
            if(current->child.find({first,last})==current->child.end())
            {
                current->child[{first,last}] = new node();
            }
            current=current->child[{first,last}];
            ans+=current->count;
        }
        current->count++;
        return ans;
    }
    long long countPrefixSuffixPairs(vector<string>& words) 
    {
        node*head=new node();
        long long result=0;
        for(int i=0;i<words.size();i++)
        {
            result+=insert(words[i],head);
        }
        return result;
    }
};