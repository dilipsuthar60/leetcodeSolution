class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat)
    {
        unordered_map<string,int>mp;
        int n=mat.size();
        int m=mat[0].size();
        string s1,s2;
        for(int i=0;i<n;i++)
        {
            
            s1=s2="";
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    s1.push_back('1');
                    s2.push_back('0');
                }
                else
                {
                      s1.push_back('0');
                    s2.push_back('1');
                }
            }
            mp[s1]++;
            mp[s2]++;
        }
        int ans=0;
        for(auto it:mp)
        {
            ans=max(ans,it.second);
        }
        return ans;
    }
};