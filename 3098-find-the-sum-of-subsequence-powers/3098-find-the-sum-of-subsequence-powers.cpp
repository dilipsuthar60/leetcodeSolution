class Solution {
public:
    const int mod=1e9+7;
    long long dp[52][52][52][2];
    long long find(vector<int>&nums,int k,int diff,int index,int isPresent=0,int prev=-1)
    {
        if(k==0&&isPresent) return diff;
        if(index>=nums.size()||k<0)
        {
            return 0;
        }
        if(dp[index][prev+1][k][isPresent]!=-1) return dp[index][prev+1][k][isPresent]%mod;
        long long ans = find(nums,k,diff,index+1,isPresent,prev);
        int found=isPresent;
        if(prev==-1||(nums[index]-nums[prev])>=diff)
        {
            if(prev!=-1&&(nums[index]-nums[prev])==diff)
            {
                found=1;
            }
            ans+=find(nums,k-1,diff,index+1,found,index);
        }
        return dp[index][prev+1][k][isPresent] = ans%mod;
    }
    int sumOfPowers(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mp[abs(nums[j]-nums[i])]++;
            }
        }
        long long ans=0;
        for(auto &[key,value]:mp)
        {
            memset(dp,-1,sizeof(dp));
            ans+=find(nums,k,key,0);
            ans%=mod;
        }
        return ans;
    }
};