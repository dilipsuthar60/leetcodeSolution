class Solution
{
    public:
        int freq[30];
    int find(string &s, int k)
    {
        int n = s.size();
        for (int ch = 0; ch < 26; ch++)
        {
            if (freq[ch] < k + 2)
            {   
                continue;
            }
            int count = 0;
            int len = 0;
            for (int i = 0; i < n; i++)
            {
                if (ch == (s[i] - 'a'))
                {
                    len++;
                }
                else
                {
                    len = 0;
                }
                count += (len >= k);
                if (count >= 3)
                {
                    return true;
                }
            }
        }
        return false;
    }
    int maximumLength(string s)
    {
        memset(freq,0,sizeof(freq));
        int n = s.size();
        int l = 1;
        int r = n;
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (find(s, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};