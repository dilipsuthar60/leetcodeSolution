class Solution {
public:
    int getDistinctNumber(vector<int>&nums){
        unordered_map<int,int>mp;
        for(auto &it:nums) mp[it]++;
        return mp.size();
    }
    int get(vector<int>&nums,int k){
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0,n=nums.size(),j=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                if(--mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
            count+=(i-j+1);
        }
        return count;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        int k = getDistinctNumber(nums);
        return get(nums,k)-get(nums,k-1);
    }
};