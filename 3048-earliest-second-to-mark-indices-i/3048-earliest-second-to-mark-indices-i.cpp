class Solution {
public:
    int find(vector<int>&nums,vector<int>&changeIndices,int mid)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<mid;i++)
        {
            mp[changeIndices[i]]=i;
        }
        if(mp.size()!=nums.size()) return false;
        int count=0;
        for(int i=0;i<mid;i++)
        {
            if(i==mp[changeIndices[i]])
            {
                if(nums[changeIndices[i]-1]>count) return false;
                count-=nums[changeIndices[i]-1];
            }
            else
            {
                count++;
            }
        }
        return true;
    }
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices)
    {
        int n=nums.size();
        int l=0;
        int r=changeIndices.size();
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,changeIndices,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};