class Solution {
public:
    int shortestSubarray(vector<int>&A, int k) 
    {
        int n=A.size();
        vector<long long>nums(n+1,0);
        for(int i=0;i<n;i++)
        {
            nums[i+1]+=nums[i]+A[i];
        }
        deque<int>dq;
        int ans=1e8;
        for(int i=0;i<=n;i++)
        {
            while(dq.size()&&nums[dq.back()]>=nums[i])
            {
                dq.pop_back();
            }
            while(dq.size()&&nums[i]-nums[dq.front()]>=k)
            {
                ans=min(ans,i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        return ans==1e8?-1:ans;
    }
};