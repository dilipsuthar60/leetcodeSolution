class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
       vector<int>nums1,nums2;
        for(int i=0;i<s.size();i++)
        {
            if(s.substr(i,a.size())==a)
            {
                nums1.push_back(i);
            }
            if(s.substr(i,b.size())==b)
            {
                nums2.push_back(i);
            }
        }
        vector<int>ans;
        int i=0;
        int j=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(abs(nums1[i]-nums2[j])<=k)
            {
                ans.push_back(nums1[i]);
            }
            if(nums1[i]-nums2[j]>k)
            {
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};