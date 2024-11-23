class Solution {
public:
    bool find(vector<int>&nums,int index,int sum,int k,int target,vector<bool>&vis)
    {
        if(k==1)
        {
            return true;
        }
        if(sum==target)
        {
            return find(nums,0,0,k-1,target,vis);
        }
        for(int i=index;i<nums.size();i++)
        {
            if(vis[i]==false)
            {
                vis[i]=true;
                if(nums[i]+sum<=target&&find(nums,i+1,nums[i]+sum,k,target,vis))
                {
                    return true;
                }
                vis[i]=false;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) 
    {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4)
        {
            return false;
        }
        int n=nums.size();
        vector<bool>vis(n,false);
        sum=sum/4;
        return find(nums,0,0,4,sum,vis);
    }
};