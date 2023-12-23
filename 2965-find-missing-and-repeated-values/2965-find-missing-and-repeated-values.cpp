class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& mat) 
    {
        vector<int>ans={-1,-1};
        int n=mat.size();
        int hash[n*n+1];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                hash[mat[i][j]]++;
            }
        }
        for(int i=1;i<=n*n;i++)
        {
            if(hash[i]==0)
            {
                ans[1]=i;
            }
            if(hash[i]>1)
            {
                ans[0]=i;
            }
        }
        return ans;
    }
};