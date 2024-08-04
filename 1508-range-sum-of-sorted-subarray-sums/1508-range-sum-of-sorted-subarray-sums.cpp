class Solution {
public:
    const int m=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i+1});
        }
        int sum=0;
        for(int i=1;i<=right;i++)
        {
            auto it=pq.top();
            pq.pop();
            if(i>=left)
            {
                sum=(sum+it.first)%m;
            }
            if(it.second<n)
            {
                it.first+=nums[it.second++];
                pq.push(it);
            }
            
        }
        return sum;
    }
};