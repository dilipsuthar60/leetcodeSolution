class Solution {
public:
    string find(string s)
    {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            sum=sum+(s[i]-'0');
        }
        return to_string(sum);
    }
    int getLucky(string s, int k) 
    {
      string str;
        for(int i=0;i<s.size();i++)
        {
            str+=to_string (s[i]-'a'+1);
        }
        while(k--)
        {
            str=find(str);
        }
        return stoi(str);
    }
};