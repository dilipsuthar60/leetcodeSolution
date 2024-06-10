class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<5005>dp;
        dp[0]=1;
        for(int i=0;i<mat.size();i++)
        {
            bitset<5005>temp;
            for(int j=0;j<mat[0].size();j++)
            {
                temp=temp|(dp<<mat[i][j]);
            }
            dp=temp;
        }
        int result=1e9;
        for(int i=0;i<5005;i++)
        {
            if(dp[i])
            result=min(result,abs(i-target));
        }
        return result;
    }
};