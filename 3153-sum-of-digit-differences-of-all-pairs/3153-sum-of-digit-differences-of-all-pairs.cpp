class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        int sizeOfDigit=to_string(nums.front()).size();
        vector<vector<long long>>map(sizeOfDigit,vector<long long>(10,0));
        for(auto it:nums){
            string s=to_string(it);
            for(int i=0;i<s.size();i++)
            {
                map[i][s[i]-'0']++;
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