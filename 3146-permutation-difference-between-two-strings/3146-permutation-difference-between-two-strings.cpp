class Solution {
public:
    int findPermutationDifference(string s, string t) 
    {
        vector<int>mapingOfIndexForS(26,0);
        for(int index=0;index<s.size();index++)
        {
            mapingOfIndexForS[s[index]-'a']=index;
        }
        int result=0;
        for(int i=0;i<t.size();i++)
        {
            result+=abs(i-mapingOfIndexForS[t[i]-'a']);
        }
        return result;
    }
};