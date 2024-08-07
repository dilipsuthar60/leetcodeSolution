class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n=nums.size();
        int freq[100005]={0};
        int element_freq[100005]={0};
        int ans=1;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            element_freq[freq[nums[i]]]++;
            if(freq[nums[i]]*element_freq[freq[nums[i]]]==i+1)
            {
                if(i+1<n) ans=i+2;
            }
            if(freq[nums[i]]*element_freq[freq[nums[i]]]==i)
            {
                ans=i+1;
            }
        }
        return ans;
    }
};