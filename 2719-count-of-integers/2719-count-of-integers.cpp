class Solution {
public:
    int mod=1e9+7;
    long long dp[410][23][2][2];
    long long find(string &s1,string &s2,int value,int index,int tight1=1,int tight2=1)
    {
        if(value<0)
        {
            return 0;
        }
        if(index==s2.size())
        {
            return 1;
        }
        if(dp[value][index][tight1][tight2]!=-1)
        {
            return dp[value][index][tight1][tight2]%mod;
        }
        int lo=tight1?s1[index]-'0':0;
        int hi=tight2?s2[index]-'0':9;
        long long count=0;
        for(int i=lo;i<=hi;i++)
        {
            count+=find(s1,s2,value-i,index+1,tight1&(i==lo),tight2&(i==hi));
        }
        return dp[value][index][tight1][tight2]= count%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        memset(dp,-1,sizeof(dp));
        num1=string(num2.size()-num1.size(),'0')+num1;
        long long count1=find(num1,num2,max_sum,0);
        memset(dp,-1,sizeof(dp));
        long long count2=find(num1,num2,min_sum-1,0);
        return (count1-count2+mod)%mod;
    }
};