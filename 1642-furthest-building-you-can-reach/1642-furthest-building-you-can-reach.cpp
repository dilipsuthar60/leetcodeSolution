class Solution {
public:
    int furthestBuilding(vector<int>&nums, int b, int l)
    {
        int n=nums.size();
        multiset<int>s;
        for(int i=0;i<n-1;i++)
        {
            int diff=nums[i+1]-nums[i];
            if(diff>0)
            {
                s.insert(diff);
                if(s.size()>l)
                {
                    b=b-*s.begin();
                    s.erase(s.begin());
                    if(b<0)
                    {
                        return i;
                    }
                }
            }
        }
        return n-1;
    }
};