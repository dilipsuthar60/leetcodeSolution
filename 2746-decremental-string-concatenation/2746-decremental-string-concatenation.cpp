class Solution {
public:
    int n;
    int dp[1001][26][26];
    int find(vector<string>&nums,int index,char f,char b)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index][f-'a'][b-'a']!=-1)
        {
            return dp[index][f-'a'][b-'a'];
        }
        int first=1e9;
        int second=1e9;
        int value=nums[index].size();
        first=min(first,((nums[index].front()==b)?value-1:value)+find(nums,index+1,f,nums[index].back()));
        second=min(second,((nums[index].back()==f)?value-1:value)+find(nums,index+1,nums[index].front(),b));
        return dp[index][f-'a'][b-'a']= min(first,second);
    }
    int minimizeConcatenatedLength(vector<string>&nums)
    {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return nums[0].size()+find(nums,1,nums[0].front(),nums[0].back());
    }
};