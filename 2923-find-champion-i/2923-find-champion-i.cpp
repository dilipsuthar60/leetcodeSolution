class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=n-1;
        for(int i=0;i<n;i++)
        {
            int temp=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&grid[i][j]!=1)
                {
                    temp=0;
                }
            }
            if(temp)
            {
                ans=i;
            }
        }
        return ans;
    }
};