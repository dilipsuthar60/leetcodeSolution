class Solution {
public:
    int maxTwoEvents(vector<vector<int>>&nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[&](auto &v1,auto &v2){return v1[1]<v2[1];});
        int ans=nums[0][2];
        for(int i=1;i<n;i++)
        {
            int s=nums[i][0];
            int e=nums[i][1];
            int cost=nums[i][2];
            nums[i][2]=max(nums[i][2],nums[i-1][2]);
            int l=0;
            int r=i-1;
            int index=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(nums[mid][1]<s)
                {
                    index=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(index!=-1)
            {
                cost+=nums[index][2];
            }
            ans=max(ans,cost);
        }
        return ans;
    }
};