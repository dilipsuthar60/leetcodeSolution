class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int n=s.size();
        vector<int>left(26,-1),right(26,-1);
        for(int i=0;i<n;i++)
        {
            if(left[s[i]-97]==-1)
            {
                left[s[i]-97]=i;
            }
            right[s[i]-97]=i;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            int l=left[i];
            int r=right[i];
            if(l!=-1&&r!=-1)
            {
            vector<int>v(26,0);
            for(int i=l+1;i<r;i++)
            {
                if(v[s[i]-97]==0)
                {
                    v[s[i]-97]=1;
                    count++;
                }
            }
            }
        }
        return count;
    }
};