class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        multiset<int>s;
        for(auto &it:nums) s.insert(it);
        int ans=-1e9;
        for(int i=0;i<n;i++){
            s.erase(s.find(nums[i]));
            sum-=nums[i];
            if((sum%2==0)&&s.find(sum/2)!=s.end()){
                ans=max(ans,nums[i]);
            }
            s.insert(nums[i]);
            sum+=nums[i];
        }
        return ans;
    }
};