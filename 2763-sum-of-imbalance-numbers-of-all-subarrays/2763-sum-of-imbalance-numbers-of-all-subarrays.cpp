class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            multiset<int>s;
            int count=0;
            for(int j=i;j<n;j++)
            {
                if(s.find(nums[j])!=s.end())
                {
                    total+=count;
                    continue;
                }
                auto it=s.insert(nums[j]);
                auto next=it;
                auto prev=it;
                next++;
                prev--;
                if(next!=s.end() and it!=s.begin())
                {
                    if((*next)-(*prev)>1)
                    {
                        count--;
                    }
                    if((*next)-nums[j]>1)
                    {
                        count++;
                    }
                    if(nums[j]-(*prev)>1)
                    {
                        count++;
                    }
                }
                else if(next!=s.end())
                {
                    if((*next)-nums[j]>1)
                    {
                        count++;
                    }
                }
                else if(it!=s.begin())
                {
                    if(nums[j]-(*prev)>1)
                    {
                        count++;
                    }
                }
                total+=count;
            }
        }
        return total;
    }
};