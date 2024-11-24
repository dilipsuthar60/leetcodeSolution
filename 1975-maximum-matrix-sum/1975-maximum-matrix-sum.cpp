class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        long long sum=0;
        long long mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=abs(mat[i][j]);
                if(mat[i][j]<0)
                {
                    count++;
                }
                mn=min(mn,1ll*abs(mat[i][j]));
            }
        }
        if(count&1)
        {
            return sum-2*mn;
        }
        return sum;
    }
};