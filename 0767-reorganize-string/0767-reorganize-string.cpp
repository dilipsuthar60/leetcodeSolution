class Solution {
public:
    string reorganizeString(string s)
    {
        string res="";
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        while(pq.size()>1)
        {
            auto it1=pq.top();
            pq.pop();
            auto it2=pq.top();
            pq.pop();
            res+=it1.second;
            res+=it2.second;
            it1.first--;
            it2.first--;
            if(it1.first>0)
            {
                pq.push(it1);
            }
            if(it2.first>0)
            {
                pq.push(it2);
            }
        }
        if(!pq.empty())
        {
            if(pq.top().first>1)
            {
                return "";
            }
            else
            {
                res+=pq.top().second;
            }
        }
        return res;
    }
};