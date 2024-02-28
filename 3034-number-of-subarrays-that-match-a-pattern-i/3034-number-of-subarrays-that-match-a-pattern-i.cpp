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
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        string text="";
        string pat="";
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1]) text+='a';
            else if(nums[i]>nums[i+1]) text+='b';
            else text+='c';
        }
        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]==1) pat+='a';
            else if(pattern[i]==-1) pat+='b';
            else pat+='c';
        }
        cout<<text<<"   ll   "<<pat<<endl;
        vector<int>lps=longestPrefix(text,pat);
        int count=0;
        for(auto it:lps)
        {
            count+=(it==pattern.size());
        }
        return count;
    }
};