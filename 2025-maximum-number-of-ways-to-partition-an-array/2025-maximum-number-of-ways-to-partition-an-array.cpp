class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        unordered_map<long long,int>left,right;
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(i!=n-1)
            right[sum]++;
        }
        int ans=0;
        if(sum%2==0)
        {
            ans=right[sum/2];
        }
        long long pref=0;
        for(int i=0;i<n;i++)
        {
            pref+=nums[i];
            long long new_sum=sum+k-nums[i];
            if(new_sum%2==0)
            {
                long long left_part=new_sum/2;
                long long right_part=(new_sum/2-k+nums[i]);
                ans=max(ans,left[left_part]+right[right_part]);
            }
            left[pref]++;
            right[pref]--;
        }
        return ans;
    }
};