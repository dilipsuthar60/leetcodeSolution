class Solution {
public:
    vector<int>dp[30004+19];
    int count=0;
    int find(int node,vector<int>&value,int k,int p=-1)
    {
        int sum=value[node];
        for(auto it:dp[node])
        {
            if(it!=p)
            {
                sum+=find(it,value,k,node);
            }
        }
        if(sum%k==0)
        {
            count++;
        }
        return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        find(0,values,k);
        return count;
    }
};