class Solution {
public:
    long long atMostk(vector<int>&nums,int k)
    {
        int j=0;
        int n=nums.size();
        long long count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            while(mp.size()>k)
            {
                if(--mp[nums[j]]==0)
                {
                    mp.erase(nums[j]);
                }
                j++;
            }
            count+=(i-j+1);
        }
        return count;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        int n=nums.size();
        long long totalSubarray=1ll*n*(n+1)/2;
        int l=1;
        int r=unordered_set<int>(nums.begin(),nums.end()).size();
        int medien=1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(atMostk(nums,mid)*2>=totalSubarray)
            {
                medien=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return medien;
    }
};