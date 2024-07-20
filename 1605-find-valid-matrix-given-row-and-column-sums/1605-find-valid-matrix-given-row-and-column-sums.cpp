class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col)
    {    
        int n=row.size();
        int m=col.size();
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                v[i][j]=min(row[i],col[j]);
                row[i]=row[i]-v[i][j];
                col[j]=col[j]-v[i][j];
            }
        }
        return v;
    }
};