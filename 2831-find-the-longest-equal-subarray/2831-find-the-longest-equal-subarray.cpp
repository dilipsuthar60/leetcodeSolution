class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) 
    {
        int len=0;
        unordered_map<int,int>mp;
        int max_freq=0;
        int n=nums.size();
        for(int i=0,j=0;i<n;i++)
        {
            max_freq=max(max_freq,++mp[nums[i]]);
            while((i-j+1-max_freq)>k)
            {
                mp[nums[j]]--;
                j++;
            }
            len=max(len,i-j+1);
        }
        return max_freq;
    }
};