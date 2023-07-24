class Solution {
public:
    bool isVowel(char ch)
    {
        string allVowel="aeiouAEIOU";
        return allVowel.find(ch)!=string::npos;
    }
    string sortVowels(string s) 
    {
        int n=s.size();
        vector<char>v;
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0,j=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                s[i]=v[j++];
            }
        }
        return s;
    }
};