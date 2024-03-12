class Solution
{
    public:
        long long maximumHappinessSum(vector<int> &nums, int k)
        {
            long long result = 0;
            sort(nums.rbegin(), nums.rend());
            for (int i = 0; i < k; i++)
            {
                if(nums[i]-i<0) break;
                result += (nums[i] - i);
            }
            return result;
        }
};