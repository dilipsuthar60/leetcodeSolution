class Solution {
public:
    int find(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        {
            return 1;
        }
        return -1;
    }
    long long beautifulSubstrings(string s, int k) 
    {
        int n=s.size();
        unordered_map<int,vector<int>>mp;
        mp[0].push_back(-1);
        int sum=0;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=find(s[i]);
            if(mp.find(sum)!=mp.end())
            {
                for(auto &key:mp[sum])
                {
                    int len=(i-key);
                    if((1ll*len*len)%(4*k)==0)
                    {
                        ans++;
                    }
                }
            }
            mp[sum].push_back(i);
        }
        return ans;
    }
};