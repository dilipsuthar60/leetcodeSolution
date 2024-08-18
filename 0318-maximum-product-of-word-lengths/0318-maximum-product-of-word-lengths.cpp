class Solution
{
    public:
    int getMask(string &s){
        int mask=0;
        for(int i=0;i<s.size();i++){
            mask|=1<<(s[i]-'a');
        }
        return mask;
    }
        int maxProduct(vector<string> &nums)
        {
            int n = nums.size();
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int mask1=getMask(nums[i]);
                    int mask2=getMask(nums[j]);
                    if((mask1&mask2)==0) ans=max(ans,(int)nums[i].size()*(int)nums[j].size());                    
                }
            }
            return ans;
        }
};