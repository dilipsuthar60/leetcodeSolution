class Solution {
public:
    vector<int> asteroidCollision(vector<int>&nums) 
    {
        int n=nums.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                s.push(nums[i]);
            }
            else
            {
                while(s.size()&&s.top()<-nums[i]&&s.top()>0)
                {
                    s.pop();
                }
                if(s.size()&&s.top()>0&&s.top()==-nums[i])
                {
                    s.pop();
                }
               else if(s.size()&&s.top()>0&&s.top()>-nums[i])
                {
                    
                }
                else
                {
                    s.push(nums[i]);
                }
            }
        }
        vector<int>ans(s.size(),0);
        int index=s.size()-1;
        while(s.size())
        {
            ans[index--]=s.top();
            s.pop();
        }
        return ans;
    }
};