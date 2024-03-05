class Solution {
public:
    int find(vector<int>&nums,int window,long long k)
    {
        if(window==0) return false;
        int n=nums.size();
        vector<long long>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=nums[i];
            prefix[i]+=prefix[i-1];
        }
        for(int l=0,r=window-1;r<n;l++,r++)
        {
            int mid=(l+r)/2;
            long long leftOperation = 1ll*nums[mid]*(mid-l+1)-(prefix[mid]-((l>0)?prefix[l-1]:0));
            long long rightOperation = (prefix[r]-prefix[mid])-1ll*nums[mid]*(r-mid);
            if(leftOperation+rightOperation<=k)
            {
                return true;
            }
        }
        return false;
    }
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int l=1;
        int r=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(find(nums,mid,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};