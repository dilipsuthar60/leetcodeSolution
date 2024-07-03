class Solution {
public:
    bool valid(string s)
    {
        if(s.size()>3||s.size()==0)
        {
            return false;
        }
        if(s[0]=='0'&&s.size()>1)
        {
            return false;
        }
        if(stoi(s)<0||stoi(s)>255)
        {
            return false;
        }
        return true;
    }
    void find(string &s,int index,string curr,vector<string>&ans,int dot)
    {
        if(dot==3)
        {
            if(valid(s.substr(index)))
            {
                ans.push_back(curr+s.substr(index));
            }
            return ;
        }
        for(int i=index;i<s.size();i++)
        {
            if(valid(s.substr(index,i-index+1)))
            {
                curr.push_back(s[i]);
                curr.push_back('.');
                find(s,i+1,curr,ans,dot+1);
                curr.pop_back();
                
            }
        }
     }
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string>ans;
        find(s,0,"",ans,0);
        return ans;
    }
};