class Solution {
public:
    long long countCompleteDayPairs(vector<int>& nums) {
        int n=nums.size();
        long long hash[30]={0};
        long long count=0;
        for(int i=0;i<n;i++)
        {
            count+=hash[(24- nums[i]%24)%24];
            hash[nums[i]%24]++;
        }
        return count;
    }
};