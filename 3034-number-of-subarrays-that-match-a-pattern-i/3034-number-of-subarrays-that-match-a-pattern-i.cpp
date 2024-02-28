class Solution {
public:
    vector<int>longestPrefix(string &s,string&p)
    {
        s=p+"#+"+s;
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
        return lps;
    }
    string convertToString(vector<int>&v)
    {
        string s="";
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==-1){
                s+='2';
            }
            else
            s+=to_string(v[i]);
        }
        return s;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int>arr;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                arr.push_back(1);
            }
            else if(nums[i]>nums[i+1])
            {
                arr.push_back(-1);
            }
            else
            {
                arr.push_back(0);
            }
        }
        string s1=convertToString(arr);
        string s2=convertToString(pattern);
        vector<int>lps=longestPrefix(s1,s2);
        int count=0;
        for(auto it:lps)
        {
            count+=(it==pattern.size());
        }
        return count;
    }
};