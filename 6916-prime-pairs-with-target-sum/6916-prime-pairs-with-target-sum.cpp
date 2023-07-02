class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) 
    {
        const int N=n+1;
        int prime[N];
        for(int i=2;i<N;i++)
        {
            prime[i]=1;
        }
        for(int i=2;i<N;i++)
        {
            if(prime[i])
            {
                for(int j=2*i;j<N;j+=i)
                {
                    prime[j]=0;
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=2;i<=n/2;i++)
        {
            if(prime[i]&&prime[n-i])
            {
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};