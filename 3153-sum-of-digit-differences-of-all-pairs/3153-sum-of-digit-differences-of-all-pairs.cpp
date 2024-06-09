class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        int sizeOfDigit=to_string(nums.front()).size();
        long long map[sizeOfDigit][10];
        memset(map,0,sizeof(map));
        for(int i=0;i<sizeOfDigit;i++)
        {
            for(int j=0;j<n;j++)
            {
                map[i][nums[j]%10]++;
                nums[j]/=10;
            }
        }
        long long result=0;
        for(int i=0;i<sizeOfDigit;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(int k=j+1;k<10;k++)
                {
                    result+=map[i][j]*map[i][k];
                }
            }
        }
        return result;
    }
};