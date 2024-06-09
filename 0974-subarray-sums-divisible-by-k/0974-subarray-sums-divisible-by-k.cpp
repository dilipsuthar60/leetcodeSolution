class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k)
    {
        unordered_map<int,int>mp;
        int sum=0;
        int n=A.size();
        int count=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(mp.find(((sum%k)+k)%k)!=mp.end())
            {
                count+=mp[((sum%k)+k)%k];
            }
            mp[((sum%k)+k)%k]++;
        }
        return count;
    }
};