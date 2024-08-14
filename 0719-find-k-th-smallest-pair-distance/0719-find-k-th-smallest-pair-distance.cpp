class Solution 
{
public:
    int find(vector<int>&nums,int mid)
    {
        int j=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            while(nums[i]-nums[j]>mid)
            {
                j++;
            }
            count+=i-j;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0;
        int r=*max_element(nums.begin(),nums.end());
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,mid)>=k)
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