class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat)
    {
        if(mat.empty())
        {
            return 0;
        }
         int max_area=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<int>height(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    height[j]=0;
                }
                else
                {
                    height[j]+=1;
                }
            }
            vector<int>v=height;
            sort(v.begin(),v.end());
        for(int i=0;i<m;i++)
        {
            max_area=max(max_area,v[i]*(m-i));
        }
        }
        return max_area;
    }
};