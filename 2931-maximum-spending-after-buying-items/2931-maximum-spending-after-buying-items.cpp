class Solution {
public:
    long long maxSpending(vector<vector<int>>& nums) {
        long long result=0;
        long long day=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++){
            pq.push({nums[i][m-1],i,m-1});
        }
        while(pq.size())
        {
            auto [cost,i,j]=pq.top();
            pq.pop();
            result+=cost*(day+1);
            day++;
            if(j-1>=0)
            pq.push({nums[i][j-1],i,j-1});
        }
        return result;
    }
};
