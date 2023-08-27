class Solution {
public:
    bool canCross(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int,unordered_set<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].insert(0);
        }
        mp[nums[0]].insert(1);
        for(int i=0;i<n;i++)
        {
            auto it=mp[nums[i]];
            for(auto jump:it)
            {
                if(jump<=0)
                {
                    continue;
                }
                int pos=nums[i]+jump;
                if(pos==nums[n-1])
                {
                    return true;
                }
                if(mp.count(pos))
                {
                    if(jump-1>=0)
                    {
                    mp[pos].insert(jump-1);
                    }
                    mp[pos].insert(jump);
                    mp[pos].insert(jump+1);
                }
            }
        }
        return false;
    }
};