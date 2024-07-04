class Solution {
public:
    long long makeSubKSumEqual(vector<int>& nums, int k) {
        int n=nums.size();
        long long result=0;
        k=__gcd(k,n);
        for(int i=0;i<k;i++)
        {
            vector<int>current;
            for(int j=i;j<n;j+=k) current.push_back(nums[j]);
            sort(current.begin(),current.end());
            int size=current.size();
            for(int j=0;j<size;j++){
                result+=abs(current[j]-current[size/2]);
            }
        }
        return result;
    }
};