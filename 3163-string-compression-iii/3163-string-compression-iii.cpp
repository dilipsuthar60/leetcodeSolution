class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int n=word.size();
        vector<pair<char,int>>v;
        for(int i=0;i<n;i++)
        {
            if(v.size()&&v.back().first==word[i])
            {
                v.back().second++;
            }
            else{
                v.push_back({word[i],1});
            }
        }
        for(auto item:v)
        {
            int currentCount=item.second;
            char ch=item.first;
            while(currentCount>=9)
            {
                ans+=to_string(9)+string(1,ch);
                currentCount-=9;
            }
            if(currentCount)
            {
                ans+=to_string(currentCount)+string(1,ch);
            }
        }
        return ans;
    }
};