class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>&mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int val=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                 val|=(1<<j);
            }
            if(val==0)
            {
                return {i};
            }
            for(int j=1;j<=32;j++)
            {
                if((j&val)==0&&mp.find(j)!=mp.end())
                {
                    vector<int>v={i,mp[j]};
                    sort(v.begin(),v.end());
                    return v;
                }
            }
            mp[val]=i;
        }
        return {};
    }
};