class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<5005>dp;
        dp[0]=1;
        for(auto &col:mat)
        {
            bitset<5005>temp;
            for(auto &item:col)
            {
                temp=temp|(dp<<item);
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