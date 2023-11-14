class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>left(26,-1),right(26,-1);
        int n=s.size();
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
            vector<int>visited(26,0);
            if(left[i]==-1||right[i]==-1)
            {
                continue;
            }
            for(int j=left[i]+1;j<right[i];j++)
            {
                if(visited[s[j]-97]==0)
                {
                    visited[s[j]-97]=1;
                    count++;
                }
            }
        }
        return count;
    }
};