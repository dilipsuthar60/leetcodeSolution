class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) 
    {
        vector<string>ans;
        for(auto it:words)
        {
            string curr="";
            stringstream s(it);
            while(getline(s,curr,separator))
            {
                if(curr.size())
                {
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};