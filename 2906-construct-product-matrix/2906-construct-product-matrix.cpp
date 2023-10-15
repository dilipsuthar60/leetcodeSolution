class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<long long>>prefix(n,vector<long long>(m,1));
        vector<vector<long long>>suffix(n,vector<long long>(m,1));
        int mod=12345;
        long long curr=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                prefix[i][j]=curr;
                curr*=mat[i][j];
                curr%=mod;
            }
        }
        curr=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                suffix[i][j]=curr;
                curr*=mat[i][j];
                curr%=mod;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=prefix[i][j]*suffix[i][j];
                mat[i][j]%=mod;
            }
        }
        return mat;
    }
};