class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int longestLen=0;
        int sizeOfnums=nums.size();
        unordered_map<int,int>mp;
        for(int i=0,j=0;i<sizeOfnums;i++)
        {
            mp[nums[i]]++;
            while(mp[nums[i]]>k)
            {
                mp[nums[j]]--;
                j++;
            }
            longestLen=max(longestLen,i-j+1);
        }
        return longestLen;
    }
};