class Solution {
public:
    vector<int>longestPrefixAndSuffix(string &text,string &pattern)
    {
        string s=pattern+"#"+text;
        int n=s.size();
        vector<int>lps(n,0);
        int i=1;
        int len=0;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                lps[i]=++len;
                i++;
            }
            else
            {
                if(len>0)
                {
                    len=lps[len-1];
                }
                else
                {
                    i++;
                }
            }
        }
        vector<int>patternIndex;
        for(int i=0;i<n;i++)
        {
            if(lps[i]==pattern.size())
            {
                patternIndex.push_back(i-2*pattern.size());
            }
        }
        return patternIndex;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>nums1=longestPrefixAndSuffix(s,a);
        vector<int>nums2=longestPrefixAndSuffix(s,b);
        int i=0;
        int j=0;
        vector<int>ans;
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
            else
            {
                i++;
            }
        }
        return ans;
    }
};