class Solution {
public:
    int dp[510][1010];
    int find(vector<int>&cost,vector<int>&time,int index,int t)
    {
        if(index==cost.size())
        {
            return t>=0?0:1e9;
        }
        if(dp[index][t+501]!=-1)
        {
            return dp[index][t+501];
        }
        int take_free_painter=find(cost,time,index+1,t-1);
        int take_paid_painter=cost[index]+find(cost,time,index+1,min((int)time.size(),t+time[index]));
        return dp[index][t+501]= min(take_free_painter,take_paid_painter);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        memset(dp,-1,sizeof(dp));
        return find(cost,time,0,0);
    }
};