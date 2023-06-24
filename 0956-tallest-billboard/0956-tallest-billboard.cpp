class Solution {
public:
    int n;
    int dp[21][90005];
    int find(vector<int>&nums,int index,int diff)
    {
        if(index==n)
        {
            return diff==0?0:-1e9;
        }
        if(dp[index][diff+5000]!=-1)
        {
            return dp[index][diff+5000];
        }
        int not_take=find(nums,index+1,diff);
        int take1=nums[index]+find(nums,index+1,diff+nums[index]);
        int take2=find(nums,index+1,diff-nums[index]);
        return dp[index][diff+5000]= max({not_take,take1,take2});
    }
//     dp = dict()
//         dp[0] = 0
        
//         for i in rods:
//             cur = collections.defaultdict(int)
//             for s in dp:
//                 cur[s+i] = max(dp[s] + i, cur[s+i])
//                 cur[s] = max(dp[s], cur[s])
//                 cur[s-i] = max(dp[s], cur[s-i])
//             dp = cur
//         return dp[0]
    int tallestBillboard(vector<int>&nums) {
        n=nums.size();
        unordered_map<int,int>dp1;
        dp1[0]=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>dp2;
            for(auto &[key,value]:dp1)
            {
                dp2[nums[i]+key]=max(dp2[nums[i]+key],nums[i]+dp1[key]);
                dp2[key-nums[i]]=max(dp2[key-nums[i]],dp1[key]);
                dp2[key]=max(dp2[key],dp1[key]);
            }
            dp1=dp2;
        }
        return dp1[0];
        // memset(dp,-1,sizeof(dp));
        // int value=find(rods,0,0);
        // if(value<0)
        // {
        //     return 0;
        // }
        // return value;
    }
};