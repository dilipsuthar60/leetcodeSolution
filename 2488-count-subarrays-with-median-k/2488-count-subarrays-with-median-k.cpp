class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int yes=0;
        int count=0;
        mp[0]=1;
        for(int i=0,sum=0,n=nums.size();i<n;i++)
        {
            if(nums[i]<k)
            {
                sum--;
            }
            if(nums[i]>k)
            {
                sum++;
            }
            if(nums[i]==k)
            {
                yes=1;
            }
            if(yes)
            {
                count+=mp[sum]+mp[sum-1];
            }
            else
            {
                mp[sum]++;
            }
        }
        return count;
    }
};