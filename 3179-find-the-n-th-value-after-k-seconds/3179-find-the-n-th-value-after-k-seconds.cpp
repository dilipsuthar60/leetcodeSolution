class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int>prefix(n,1);
        const int mod=1e9+7;
        while(k--)
        {
            for(int i=1;i<n;i++)
            {
                prefix[i]+=prefix[i-1];
                prefix[i]%=mod;
            }
        }
        return prefix.back();
    }
};