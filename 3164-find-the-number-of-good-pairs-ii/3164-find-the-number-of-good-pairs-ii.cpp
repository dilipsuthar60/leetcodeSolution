class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]*k]++;
        }
        long long result=0;
        for(int i=0;i<n;i++)
        {
            int currentElement=nums1[i];
            for(int i=1;i*i<=currentElement;i++)
            {
                if(currentElement%i==0)
                {
                    result+=mp[i];
                    if(currentElement/i!=i){
                        result+=mp[currentElement/i];
                    }
                }
            }
        }
        return result;
    }
};