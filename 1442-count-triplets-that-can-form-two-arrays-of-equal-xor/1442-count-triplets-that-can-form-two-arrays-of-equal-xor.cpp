class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        vector<int>prefixXor={0};
        for(auto &it:nums){
            prefixXor.push_back(prefixXor.back()^it);
        }
        for(int i=0;i<n+1;i++)
        {
            for(int j=i+1;j<n+1;j++)
            {
                if(prefixXor[i]==prefixXor[j]){
                    result+=(j-i-1);
                }
            }
        }
        return result;
    }
};